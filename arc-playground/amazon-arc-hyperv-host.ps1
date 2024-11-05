param(
    [Parameter(Mandatory=$false)][string]$suffixNr="",
    [Parameter(Mandatory=$false)][string]$resourceGroupName="amazon-arc-playground-rg" + $suffixNr,
    [Parameter(Mandatory=$false)][string]$location="westeurope",
    [Parameter(Mandatory=$false)][string]$sshKey=$env:USERPROFILE + "\.ssh\id_rsa",
    [Parameter(Mandatory=$false)][string]$vmHostname="awslinux20-vm" + $suffixNr,
    [Parameter(Mandatory=$false)][string]$vmMachinesDir="c:\vms\",
    # TODO Download iso Automatically
    # https://cdn.amazonlinux.com/os-images/2.0.20241014.0/hyperv/amzn2-hyperv-2.0.20241014.0-x86_64.xfs.gpt.vhdx.zip
    [Parameter(Mandatory=$true)][string]$awsRootfs="C:\Users\" + $env:USERPROFILE + "\Downloads\amzn2-hyperv-2.0.20241014.0-x86_64.xfs.gpt.vhdx",
    #                                                                 C:\Users\kkanas\Downloads\amzn2-hyperv-2.0.20241014.0-x86_64.xfs.gpt.vhdx-5
    [Parameter(Mandatory=$true)][string]$vmCloudInitIso="C:\vms\" + $vmHostname + "\seed.iso",
    [Parameter(Mandatory=$false)][bool]$awsRootfsCopyToVmMachinesDir=$false,
    # URLS for policy zip file, and policy json
    [Parameter(Mandatory=$false)][string]$baseline_release_url="https://github.com/Azure/azure-osconfig/releases/download/oconfig_for_mc/AzureLinuxBaseline.zip",
    [Parameter(Mandatory=$false)][string]$baseline_release_policy_json_url="https://github.com/Azure/azure-osconfig/releases/download/ignite_2024/AzureLinuxBaseline_DeployIfNotExists.json",
    [Parameter(Mandatory=$false)][string]$baseline_release_dir=".\tmp-policy",
    [Parameter(Mandatory=$false)][string]$policy_name="AzureLinuxBaseline policy " + $suffixNr

)

# Derived vars
$sshPubKey=$sshKey + ".pub"
$vmMachinesPath = $vmMachinesDir + $vmHostname

# vm rootfs is rootfs from Amazon Linux 2
$vmRootfs=$awsRootfs

# check if we are running as admin
if ( -Not([Security.Principal.WindowsIdentity]::GetCurrent().Groups -contains 'S-1-5-32-544')) {
    Write-Output "Need to run as administrator to create VM"
exit 1
}

# ssh keys cheks
if (-not (Test-Path -Path $sshKey -PathType Leaf)) {
    Write-Output "ssh key does not exist at location: " + $sshKey
    exit 2
}

if (-not (Test-Path -Path $sshPubKey -PathType Leaf)) {
    Write-Output "public ssh key does not exist at location: " + $sshPubKey
    exit 3
}

# Amazon Linux Rootfs file cheks
if (-not (Test-Path -Path $awsRootfs -PathType Leaf)) {
    Write-Output "rootfs with Amazon Linux fs does not exits at: " + $awsRootfs
    exit 4
}


if (-not (Test-Path -Path $vmMachinesPath )) {
    New-Item -Type Directory -Path $vmMachinesPath -Force | Out-Null
}

if ($awsRootfsCopyToVmMachinesDir){
    # copy Amazon Linux2 rootfs to virtual machine directory
    copy $awsRootfs $vmMachinesPath
    # set variable
    $vmRootfs = $vmMachinesPath + "\" + (Split-path -Leaf $awsRootfs)

}

$vm = Get-VM -Name $vmHostname -ErrorAction SilentlyContinue
if ($vm) {
    Write-Host "Error: " $vmHostname "exists, remove it first using:"
    Write-Host "Remove-VM -Name $vmHostname"
    exit 4
}

#  Create new VM
New-VM -Name $vmHostname -path $vmMachinesPath  -MemoryStartupBytes 1GB -Generation 1 -SwitchName "Default Switch" | Out-Null
# Add Amazon Linux 2 Rootfs
Add-VMHardDiskDrive -VMName $vmHostname -Path $vmRootfs

# Add CloudInit Nocloud.iso https://cloudinit.readthedocs.io/en/latest/reference/datasources/nocloud.html
Add-VMDvdDrive -VMName $vmHostname -Path $vmCloudInitIso
Start-VM -Name $vmHostname
Write-Host "Wating till vm  $vmHostname  starts"
while ((get-vm -name $vmHostname).state -ne 'Running') { start-sleep -s 1 }

$i=0
while ($i -le 40) {
    $vmMacAddress=(Get-VMNetworkAdapter -VMName  $vmHostname  | select -ExpandProperty MacAddress)
    if ($vmMacAddress -ne "000000000000") {
        break
    }
    Write-Host "Wating till vm $vmHostname get assigned correct MAC address"
    start-sleep 3
}

if ($vmMacAddress -eq "000000000000") {
    Write-Host "Error: VM was unable to get MacAddress assigned $vmMacAddress for $vmHostname"
    exit 5
    break
}

# Convert MacAddress from00155D01A304 -> to 'arp' notation 00-15-5d-01-a3-04
$vmMacAddressForArp=($vmMacAddress -replace '(.{2})(.{2})(.{2})(.{2})(.{2})(.{2})', '$1-$2-$3-$4-$5-$6').ToLower()
# Find Ip Address in arp neibheroud table
$i = 1
while ($i -le 40) {
    # FIXME: use native powershell api for arp table query
    $vmIp=(arp -a | findstr $vmMacAddressForArp | Select-String -Pattern "(\d{1,3}\.){3}\d{1,3}" | ForEach-Object { $_.Matches.Value })
    if ($vmIp.Length -gt 0) {
        break
    }
    Write-Host "Wating till vm $vmHostname macaddress  $vmMacAddressForArp  shows up in arp table"
    start-sleep 3
    $i++
}

if ($vmIp.Length -eq 0) {
    Write-Host "Error: unable to find IP MacAddress $vmMacAddress for $vmHostname"
    exit 6
}
#### Policy

$baseline_release_url="https://github.com/Azure/azure-osconfig/releases/download/oconfig_for_mc/AzureLinuxBaseline.zip"
$baseline_release_zip=$baseline_release_dir + "AzureLinuxBaseline.zip"
$baseline_release_policy=$baseline_release_dir + "AzureLinuxBaseline_DeployIfNotExists.json"
$baseline_release_policy_fix= $baseline_release_dir + "AzureLinuxBaseline_DeployIfNotExists.fix.json"

# Get latest policy
Invoke-WebRequest -Uri $baseline_release_url  -OutFile $baseline_release_zip
Invoke-WebRequest -Uri $baseline_release_policy_json_url -OutFile $baseline_release_policy

# calculate baseline sha256sum
$baseline_release_hash=(Get-FileHash -Path  $baseline_release_zip -Algorithm SHA256 |  select -ExpandProperty Hash)
# get policy json
$baseline_release_json =(Get-Content -Path $baseline_release_policy -Raw | ConvertFrom-Json)
# update the policy package url and update json contentHash to mach the  policy
$baseline_release_json.properties.metadata.guestConfiguration.contentUri=$baseline_release_url
$baseline_release_json.properties.metadata.guestConfiguration.contentHash=$baseline_release_hash
# write the policy json to $baseline_release_policy_fix
$baseline_release_json | ConvertTo-Json -Depth 32 | Set-Content -Path $baseline_release_policy_fix

# Create new policy definition in Azure
$policy_definition=New-AzPolicyDefinition -Name $policy_name -Policy $baseline_release_policy_fix

# Create a resource group if not exists
$resource_group = Get-AzResourceGroup -Name $resourceGroupName -ErrorAction SilentlyContinue
if ( $resource_group ) {
    if( $resource_group.Location -ne $location ) {
        Write-Error "Resource group $resourceGroupName is in a different location"
        exit 1
    }
} else {
    $resource_group = New-AzResourceGroup -Name $resourceGroupName -Location $location -Force
}
$location = $resource_group.Location
$resource_group_id = $resource_group.ResourceId
$resource_group = $resource_group.ResourceGroupName

# Assing policy to resource group
$policy_assignment_name=$policy_name + " for " + $resourceGroupName
$policy_assignment=New-AzPolicyAssignment -Name $policy_assignment_name  -DisplayName $policy_assignment_name -Scope $resource_group_id -PolicyDefinition $policy_definition -PolicyParameterObject @{'IncludeArcMachines'='true'} -IdentityType SystemAssigned -Location $location

# Handle different API versions:  legacy has Identity.PrincipalId, new API  IdentityPrincipalId
$policy_assignment_principal_id=$policy_assignment.IdentityPrincipalId ?? $policy_assignment.Identity.PrincipalId

# Check connection to Azure
$context = Get-AzContext

$access_token = Get-AzAccessToken -WarningAction Ignore
$access_token = $access_token.Token

$subscription_id = $context.Subscription.Id
$tenant_id = $context.Tenant.Id
$cloud = $context.Environment.Name
$correlation_id = New-Guid


# Build azcmagent.env file
$arc_environment_content="ARC_PLAYGROUND_SUBSCRIPTION_ID=$subscription_id" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_TENANT_ID=$tenant_id" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_RESOURCE_GROUP=$resource_group" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_LOCATION=$location" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_AUTH_TYPE=principal" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_CLOUD=$cloud" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_CORRELATION_ID=$correlation_id" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_ACCESS_TOKEN=$access_token" + "`n"
$arc_environment_content+= "ARC_PLAYGROUND_USERNAME=$env:USERNAME"

# TODO this is temp file, need to remove after copied to host
$env_file_name = $vmHostname + ".env"

# Write file
Set-Content -NoNewline -Path $env_file_name -Value $arc_environment_content
#           ^ neccessary to create Unix text file

$ssh_options="-i $sshKey -o UserKnownHostsFile=\\.\NUL -o StrictHostKeyChecking=accept-new"

$scpCmd1="scp $ssh_options $env_file_name ec2-user@${vmIp}:/tmp/azcmagent.env | Out-Null"
Invoke-Expression $scpCmd1
$scpCmd2="scp $ssh_options install_linux_acmagent_wrapper.sh ec2-user@${vmIp}:/tmp/ | Out-Null"
Invoke-Expression $scpCmd2
# TODO workaround hostname is set pernamently in iso file, if the file is not regenerated
# the $vmHostname and the system hostname can be different, if iso generation will be always generated, it won't be an issue
$sshSetHostnameCmd="ssh $ssh_options ec2-user@${vmIp} 'sudo hostnamectl set-hostname $vmHostname '"
Invoke-Expression $sshSetHostnameCmd


$sshInstallCommand="ssh $ssh_options  ec2-user@${vmIp} 'cd /tmp; sudo bash install_linux_acmagent_wrapper.sh'"
$install_log=Invoke-Expression $sshInstallCommand
if ($LASTEXITCODE -ne 0) {
    Write-Output "Error azcmagent installation failed log:"
    Write-Output $install_log
    exit $LASTEXITCODE
}

Write-host "Force policy evaluation by invoking:"
Write-host "      Start-AzPolicyComplianceScan -ResourceGroupName $ResourceGroupName"
Write-host ""
Write-host "Local connection to machine:"
Write-host "    ssh $ssh_options  ec2-user@${vmIp}"

# TODO to make following work need to prepare machine
# install  SSH Exteion and by powershell Set-AzVMExtension
# Write-host "Azure connection to machine:"
# Write-host "    az ssh arc --subscription $subscription_id --resource-group $resourceGroupName --name $vmHostname"
# Write-host "Powershell connection to machine:"
# Write-host "    $session = New-PSSession -HostName <myMachine> -UserName <localUser> -Options $options"


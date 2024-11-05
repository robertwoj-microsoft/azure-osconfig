param(
    [Parameter(Mandatory=$false)][string]$suffixNr="",
    [Parameter(Mandatory=$false)][string]$resourceGroupName="amazon-arc-playground-rg" + $suffixNr,
    [Parameter(Mandatory=$false)][string]$location="westeurope",
    [Parameter(Mandatory=$false)][string]$vmHostname="awslinux20-vm" + $suffixNr,
    [Parameter(Mandatory=$false)][string]$vmMachinesDir="c:\vms\",
    [Parameter(Mandatory=$false)][string]$baseline_release_dir=".\tmp-policy"

)

$vmMachinesPath = $vmMachinesDir + $vmHostname

# check if we are running as admin
if ( -Not([Security.Principal.WindowsIdentity]::GetCurrent().Groups -contains 'S-1-5-32-544')) {
    Write-Output "Need to run as administrator to delete VM"
exit 1
}

$vm = Get-VM -Name $vmHostname -ErrorAction SilentlyContinue
if ($vm) {
    Stop-VM -Name $vmHostname -Force
    Remove-VM -Name $vmHostname -Force
}

# remove Linux2 rootfs to virtual machine directory
Remove-Item -Path $vmMachinesPath -Recurse -Force -ErrorAction SilentlyContinue

# remove policy dirrectory to virtual machine directory
Remove-Item -Path $baseline_release_dir -Recurse -Force  -ErrorAction SilentlyContinue

#TODO remove resource group
Remove-AzResourceGroup -Name $resourceGroupName -Force -Verbose -ErrorAction SilentlyContinue


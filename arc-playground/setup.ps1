param(
    [Parameter(Mandatory=$false)][string]$resourceGroupName="azure-arc-playground-rg",
    [Parameter(Mandatory=$false)][string]$location="westeurope"
)

$ErrorActionPreference = "Stop"

$context = Get-AzContext
$subscription_id = $context.Subscription.Id
$tenant_id = $context.Tenant.Id
$cloud = $context.Environment.Name
$correlation_id = New-Guid

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

# Create an SSH policy assignment
$policy_definition = Get-AzPolicyDefinition -Id "/providers/Microsoft.Authorization/policyDefinitions/e22a2f03-0534-4d10-8ea0-aa25a6113233"
try {
    $policy_assignment = New-AzPolicyAssignment -Name "arc-playground-ssh-policy-assignment" -DisplayName "Arc Playground SSH policy assignment" -Scope $resource_group_id -PolicyDefinition $policy_definition -PolicyParameterObject @{'IncludeArcMachines'='true'} -IdentityType SystemAssigned -Location $location
} catch {
    $policy_assignment = Get-AzPolicyAssignment -Scope $resource_group_id -Name "arc-playground-ssh-policy-assignment"
}

# Guest configuration role must be assigned
$role_definition = Get-AzRoleDefinition -Name "Guest Configuration Resource Contributor"
try {
    New-AzRoleAssignment -Scope $resource_group_id -ObjectId $policy_assignment.IdentityPrincipalId -RoleDefinitionId $role_definition.Id > $null
} catch {
    # Check if the role assignment already exists, if not, the script fails
    Get-AzRoleAssignment -Scope $resource_group_id -ObjectId $policy_assignment.IdentityPrincipalId -RoleDefinitionId $role_definition.Id > $null
}

$access_token = Get-AzAccessToken -WarningAction Ignore
$access_token = $access_token.Token

Write-Output "ARC_PLAYGROUND_SUBSCRIPTION_ID=$subscription_id"
Write-Output "ARC_PLAYGROUND_TENANT_ID=$tenant_id"
Write-Output "ARC_PLAYGROUND_RESOURCE_GROUP=$resource_group"
Write-Output "ARC_PLAYGROUND_LOCATION=$location"
Write-Output "ARC_PLAYGROUND_AUTH_TYPE=principal"
Write-Output "ARC_PLAYGROUND_CLOUD=$cloud"
Write-Output "ARC_PLAYGROUND_CORRELATION_ID=$correlation_id"
Write-Output "ARC_PLAYGROUND_ACCESS_TOKEN=$access_token"
Write-Output "ARC_PLAYGROUND_USERNAME=$(whoami)"

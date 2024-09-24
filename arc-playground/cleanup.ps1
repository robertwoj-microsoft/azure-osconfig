param(
    [Parameter(Mandatory=$false)][string]$resourceGroupName="azure-arc-playground-rg",
    [Parameter(Mandatory=$false)][switch]$skipTag=$false,
    [Parameter(Mandatory=$false)][switch]$deleteResourceGroup=$false
)

$ErrorActionPreference = "Stop"

if ($skipTag) {
    # List all resources in the resource group
    $resources = Get-AzResource -ResourceGroupName $resourceGroupName
} else {
    # List resources sharing the same tag and in the resource group
    $resources = Get-AzResource -Tag @{ "PlaygroundOwner" = $(whoami) } -ResourceGroupName $resourceGroupName
}
$resources | ForEach-Object {
    $resource = $_
    $resource_name = $resource.Name
    Write-Output "Deleting $resource_name in resource group $resourceGroupName"
    Remove-AzResource -ResourceId $resource.ResourceId -Force
}

if ($deleteResourceGroup) {
    Write-Output "Deleting resource group $resourceGroupName"
    Remove-AzResourceGroup -Name $resourceGroupName -Force
}
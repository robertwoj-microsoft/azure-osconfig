#!/bin/bash
set -euo pipefail
# PS4='+${LINENO}: '
# set -x
suffix=
correlationId=$(uuidgen)
accountCtx=$(az account show --output json)

subscriptionId=$(echo -n "${accountCtx}"|jq --raw-output '.id')
tenantId=$(echo ${accountCtx}|jq --raw-output '.homeTenantId')
cloudName=$(echo ${accountCtx}|jq --raw-output '.environmentName')

# default resourceGroup and location, set to values if scrpit params empty or not set
resourceGroupName=${1:-azure-arc-playground-rg${suffix}}
location=${2:-westeurope}
createOrUseResourceGroup() {
    set +e
    resourceGroup=$(az group show --name ${resourceGroupName} 2>/dev/null)
    if [ $? -ne 0 ] ; then
        resourceGroup=$(az group create --name ${resourceGroupName} --location ${location})
        if [ $? -ne 0 ] ; then
            err=$?
            echo "Error creating resourceGroup '${resourceGroupName}' Error ${err}"
            exit 1
        fi
    fi
    set -e
}
createOrUseResourceGroup

resourceGroupLocation=$(echo ${resourceGroup} | jq --raw-output '.location')
#                                                  ^ - remove quotes from variable
resourceGroupId=$(echo ${resourceGroup} | jq --raw-output '.id' )
if  [ ${location} != ${resourceGroupLocation} ] ; then
    echo "ResourceGroup ${resourceGroup} is located in ${resourceGroupLocation} but should be in ${location}"
    echo "change location or resourceGroup parameter so their location is the same"
    exit 1
fi

# This is FIXED SSH policy
# [Preview]: Configure SSH Posture Control on Linux machines
# https://www.azadvertizer.net/azpolicyadvertizer/e22a2f03-0534-4d10-8ea0-aa25a6113233.html
# Get-AzPolicyDefinition -Id "/providers/Microsoft.Authorization/policyDefinitions/e22a2f03-0534-4d10-8ea0-aa25a6113233"
policyDefinitionName=e22a2f03-0534-4d10-8ea0-aa25a6113233
policyAssignment=$(az policy assignment create --name "arc-playground-ssh-policy-assignment-azcli${suffix}" \
    --display-name "Arc Playground SSH policy assignment azcli ${suffix}"  \
    --scope ${resourceGroupId}  \
    --policy  ${policyDefinitionName}  \
    --params  '{"IncludeArcMachines":{ "value": "true"}}' \
    --mi-system-assigned --location ${location} )
policyAssignmentPrincipialId=$(echo ${policyAssignment} | jq -r '.identity.principalId')

roleDefinitionId=$(az role definition list --name "Guest Configuration Resource Contributor" --query '[0].id'| jq -r '.' )
# loop until policyAssignmentPrincipialId is present otherwise az role assignment will fail.
# this can be overcame by using --assignee-object ${principalId} and --assignee-principal-type ServicePrincipal
while true; do
    set +e
    isServicePrincipal=$(az ad sp show --id ${policyAssignmentPrincipialId} 2>/dev/null)
    if [[ $? -eq 0 && ${isServicePrincipal} != "" ]]; then
        break;
    fi
    echo "Waiting for servicePrincipal ${policyAssignmentPrincipialId}"
    sleep 1
    set -e
done
az role assignment create  \
  --scope ${resourceGroupId} \
  --assignee ${policyAssignmentPrincipialId} \
  --role ${roleDefinitionId} > /dev/null

accessToken=$(az account get-access-token --query 'accessToken' | jq -r '.')

echo "ARC_PLAYGROUND_SUBSCRIPTION_ID=$subscriptionId"
echo "ARC_PLAYGROUND_TENANT_ID=$tenantId"
echo "ARC_PLAYGROUND_RESOURCE_GROUP=$resourceGroupName"
echo "ARC_PLAYGROUND_LOCATION=$location"
echo "ARC_PLAYGROUND_AUTH_TYPE=principal"
echo "ARC_PLAYGROUND_CLOUD=$cloudName"
echo "ARC_PLAYGROUND_CORRELATION_ID=$correlationId"
echo "ARC_PLAYGROUND_ACCESS_TOKEN=$accessToken"
echo "ARC_PLAYGROUND_USERNAME=$(whoami)"

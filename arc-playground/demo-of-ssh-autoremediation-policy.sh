#!/bin/bash
set -euo pipefail
PS4='+${LINENO}: '
set -x

RG="remediation-demo-rg"
VM="remediation-demo-vm"
LOCATION="westeurope"

# 1. Create a resource grouop
az group create --name "${RG}" --location "${LOCATION}"
RG_ID=$(az group show --resource-group "${RG}" --query id --output tsv)

# 2. Create SSH audit and remediation policy assignment
az policy assignment create --policy "e22a2f03-0534-4d10-8ea0-aa25a6113233" --name "Configure SSH Posture test machine" --scope "${RG_ID}" --mi-system-assigned --role "Guest Configuration Resource Contributor" --identity-scope "${RG_ID}" --location "${LOCATION}"

# 3. Create a test VM
az vm create --only-show-errors --generate-ssh-keys --name "${VM}" --resource-group "${RG}" --location "${LOCATION}" --image Ubuntu2204 --assign-identity '[system]'

# 4. Install configuration management extension, required for the policy to act
az vm extension set --resource-group "${RG}" --vm-name "${VM}" --name ConfigurationForLinux --publisher Microsoft.GuestConfiguration --enable-auto-upgrade

# 5. Generate temporary SSH key pair
if [ ! -f ~/.ssh/id_rsa ]; then ssh-keygen -f ~/.ssh/id_rsa -N "" > /dev/null; fi
SSH_KEY=$(cat ~/.ssh/id_rsa.pub)
USERNAME=$(whoami)

# 6. Install SSH extension for manual inspection
az vm extension set --resource-group "${RG}" --vm-name "${VM}" --name VMAccessForLinux --publisher Microsoft.OSTCExtensions --version 1.4 --protected-settings '{"username": "demouser", "ssh_key":"'"${SSH_KEY}"'"}'

# 7. Log into the VM
az ssh vm --local-user "${USERNAME}" --name "${VM}" --resource-group "${RG}" -- -o StrictHostKeyChecking=accept-new -i ~/.ssh/id_rsa


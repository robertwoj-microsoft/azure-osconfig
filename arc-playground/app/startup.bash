#!/bin/bash

# Load environment variables for Azure Arc node enrollment
source /app/env.bash

log "[INFO] Downloading azcmagent"
output=$(wget https://aka.ms/azcmagent -O /app/install_linux_azcmagent.sh 2>&1);
if [ $? != 0 ]; then
        wget -qO- --method=PUT --body-data="{\"subscriptionId\":\"${ARC_PLAYGROUND_SUBSCRIPTION_ID}\",\"{ARC_PLAYGROUND_RESOURCE_GROUP}\":\"${ARC_PLAYGROUND_RESOURCE_GROUP}\",\"{ARC_PLAYGROUND_TENANT_ID}\":\"${ARC_PLAYGROUND_TENANT_ID}\",\"location\":\"${ARC_PLAYGROUND_LOCATION}\",\"correlationId\":\"${ARC_PLAYGROUND_CORRELATION_ID}\",\"authType\":\"$authType\",\"operation\":\"onboarding\",\"messageType\":\"DownloadScriptFailed\",\"message\":\"$output\"}" "https://gbl.his.arc.azure.com/log" &> /dev/null
        die "Failed to download installation script"
fi

log "[INFO] setting up azcmagent"
/bin/bash /app/install_linux_azcmagent.sh >> ${logfile} 2>&1 || die "Failed to install required packages"

log "[INFO] Enrolling the machine as Azure Arc resource"
azcmagent connect \
	--access-token "${ARC_PLAYGROUND_ACCESS_TOKEN}" \
	--resource-group "${ARC_PLAYGROUND_RESOURCE_GROUP}" \
	--tenant-id "${ARC_PLAYGROUND_TENANT_ID}" \
	--location "${ARC_PLAYGROUND_LOCATION}" \
	--subscription-id "${ARC_PLAYGROUND_SUBSCRIPTION_ID}" \
	--correlation-id "${ARC_PLAYGROUND_CORRELATION_ID}" \
	--cloud "${ARC_PLAYGROUND_CLOUD}" \
	--tags "ArcSQLServerExtensionDeployment=Disabled,PlaygroundOwner=${ARC_PLAYGROUND_USERNAME}" \
	>> ${logfile} 2>&1 || die "Failed to enroll to Azure Arc"

echo "Portal page:"
azcmagent show "Portal Page" | cut -d ':' -f 2,3 | xargs >> ${logfile} 2>&1
log "[INFO] Success"

#!/bin/bash
set -uo pipefail

cd /tmp
source azcmagent.env

wget https://aka.ms/azcmagent -O /tmp/install_linux_azcmagent.sh 2>&1
if [ $? -ne 0 ]; then
        wget -qO- --method=PUT --body-data="{\"subscriptionId\":\"${ARC_PLAYGROUND_SUBSCRIPTION_ID}\",\"{ARC_PLAYGROUND_RESOURCE_GROUP}\":\"${ARC_PLAYGROUND_RESOURCE_GROUP}\",\"{ARC_PLAYGROUND_TENANT_ID}\":\"${ARC_PLAYGROUND_TENANT_ID}\",\"location\":\"${ARC_PLAYGROUND_LOCATION}\",\"correlationId\":\"${ARC_PLAYGROUND_CORRELATION_ID}\",\"authType\":\"$authType\",\"operation\":\"onboarding\",\"messageType\":\"DownloadScriptFailed\",\"message\":\"$output\"}" "https://gbl.his.arc.azure.com/log" &> /dev/null
        echo "Failed to download installation script"
	exit 1
fi
bash install_linux_azcmagent.sh 2>&1
if [ $? -ne 0 ] ; then
        echo "Failed to install azcmagent "
	exit 2
fi

azcmagent connect \
	--access-token "${ARC_PLAYGROUND_ACCESS_TOKEN}" \
	--resource-group "${ARC_PLAYGROUND_RESOURCE_GROUP}" \
	--tenant-id "${ARC_PLAYGROUND_TENANT_ID}" \
	--location "${ARC_PLAYGROUND_LOCATION}" \
	--subscription-id "${ARC_PLAYGROUND_SUBSCRIPTION_ID}" \
	--correlation-id "${ARC_PLAYGROUND_CORRELATION_ID}" \
	--cloud "${ARC_PLAYGROUND_CLOUD}" \
	--tags "ArcSQLServerExtensionDeployment=Disabled,PlaygroundOwner=${ARC_PLAYGROUND_USERNAME}"
if [ $? -ne 0 ] ; then
        echo "Failed to connect azcmagent "
	exit 3
fi


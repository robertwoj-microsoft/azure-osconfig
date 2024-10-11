#!/bin/bash

logfile="/var/log/arc-playground.log"
function log {
	echo $1 >> ${logfile}
}

function die {
	log "[ERROR] $1"
	exit 1
}

source /app/arc-playground.env
if [ $? -ne 0 ]; then
	die "Please mount the filled arc-playground.env file"
fi

# if [ -z ${ARC_PLAYGROUND_SERVICE_PRINCIPAL_ID} ]; then 
# 	die "Please set ARC_PLAYGROUND_SERVICE_PRINCIPAL_ID environment variable"
# fi

# if [ -z ${ARC_PLAYGROUND_SERVICE_PRINCIPAL_CLIENT_SECRET} ]; then 
# 	die "Please set ARC_PLAYGROUND_SERVICE_PRINCIPAL_CLIENT_SECRET environment variable"
# fi

if [ -z ${ARC_PLAYGROUND_SUBSCRIPTION_ID} ]; then 
	die "Please set ARC_PLAYGROUND_SUBSCRIPTION_ID environment variable"
fi

if [ -z ${ARC_PLAYGROUND_RESOURCE_GROUP} ]; then 
	die "Please set ARC_PLAYGROUND_RESOURCE_GROUP environment variable"
fi

if [ -z ${ARC_PLAYGROUND_TENANT_ID} ]; then 
	die "Please set ARC_PLAYGROUND_TENANT_ID environment variable"
fi

if [ -z ${ARC_PLAYGROUND_LOCATION} ]; then 
	die "Please set ARC_PLAYGROUND_LOCATION environment variable"
fi

if [ -z ${ARC_PLAYGROUND_AUTH_TYPE} ]; then 
	die "Please set ARC_PLAYGROUND_AUTH_TYPE environment variable"
fi

if [ -z ${ARC_PLAYGROUND_CORRELATION_ID} ]; then 
	die "Please set ARC_PLAYGROUND_CORRELATION_ID environment variable"
fi

if [ -z ${ARC_PLAYGROUND_CLOUD} ]; then 
	die "Please set ARC_PLAYGROUND_CLOUD environment variable"
fi

if [ -z ${ARC_PLAYGROUND_ACCESS_TOKEN} ]; then 
	die "Please set ARC_PLAYGROUND_ACCESS_TOKEN environment variable"
fi

if [ -z ${ARC_PLAYGROUND_USERNAME} ]; then 
	die "Please set ARC_PLAYGROUND_USERNAME environment variable"
fi
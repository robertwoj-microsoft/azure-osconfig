# azure-arc-playground
Azure Arc + OSConfig. Automates Azure Arc enrollment with azure-osconfig installed. A place to start with playing with azure-osconfig.
## Prerequisites
### Install podman CLI
Podman is a more convenient choice than docker for the systemd-based containers and systemd is required for azcmagent package installation.
If on Ubuntu 22.04, then:
```
sudo apt-get install -y podman
```
If on Windows, download [podman CLI installer](https://podman.io/) and perform the installation, reboot is required.
### Install powershell
If on Ubuntu 22.04, then:
```
sudo apt-get install -y powershell
```
On Windows powershell should already be installed.
### Install Azure powershell module
In powershell, use the following command:
```
Install-Module -Name Az -Scope CurrentUser -Repository PSGallery -AllowClobber -Force
```
### Connect Azure account
In powershell, use the following command:
```
Connect-AzAccount
```
*Note*: Currently this solution should work on personal Visual Studio subscription, be sure to chose one here.
### Setup resource group and policy assignments
```
pwsh setup.ps1 > arc-playground.env
```
This script sets up a resource group if needed, generates access token, fills in required environment variables and prints them to standard output. The `arc-playground.env` file is needed for podman containers to properly set up Azure Arc connection.
## Create podman containers
In powershell:
```
./create-containers.ps1 -Machines 2
```
This script cleans up all the previous containers and sets up new ones.
The created containers should soon be added to Azure and be visible in the portal.
The containers run a systemd service which runs our startup script via a unit file. Systemd is required by the `azcmagent` installation scripts, so the installation must happen on a running container. The installation and onboarding happens in background and you can observe status using the following command:
```
podman exec -it arc-playground-1 tail -f /var/log/arc-playground.log
```
When the setup is finished you should observe an `[INFO] Success` entry.

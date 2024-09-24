param(
	[Parameter(Mandatory=$false)][int]$machines = 1
)

# Build the container image
podman build . --tag azure-arc-playground

# Cleanup existing containers
./cleanup-containers.ps1 -machines $machines

# Create new containers
for($i=1; $i -le $machines; $i++)
{
	podman stop --ignore "arc-playground-$i"
	podman rm --ignore "arc-playground-$i"
	Write-Output "Creating container arc-playground-$i"
	podman run -d -v ${PWD}/arc-playground.env:/app/arc-playground.env:ro --name "arc-playground-$i" azure-arc-playground
}


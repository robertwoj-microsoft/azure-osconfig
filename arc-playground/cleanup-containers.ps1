param(
	[Parameter(Mandatory=$false)][int]$machines = 1
)

Write-Output "Cleaning up $machines podman containers"
for($i=1; $i -le $machines; $i++)
{
	podman stop --ignore "arc-playground-$i"
	podman rm --ignore "arc-playground-$i"
}


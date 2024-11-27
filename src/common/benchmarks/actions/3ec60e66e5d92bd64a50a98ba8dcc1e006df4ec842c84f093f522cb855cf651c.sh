#!/bin/sh

# Extract all unique group IDs (GID) from /etc/passwd
awk -F: '{print $4}' /etc/passwd | sort -u | while read gid; do
 # Check if the GID exists in /etc/group
 if ! grep -q -E "^.*:.*:$gid:" /etc/group; then
 echo "Group $gid is referenced by /etc/passwd but does not exist in /etc/group"
 fi
done
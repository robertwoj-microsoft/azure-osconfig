#!/bin/sh

# Define the path to the group file
GROUP_FILE="/etc/group"

# Extract GIDs and count occurrences
awk -F: '{print $3}' "$GROUP_FILE" | sort | uniq -c | awk '$1 > 1 {print $2}' | while read -r gid; do
 echo "Duplicate GID: $gid"
 grep -F ":$gid:" "$GROUP_FILE"
done
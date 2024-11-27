#!/bin/sh
PASSWD_FILE="/etc/passwd"

awk -F: '{print $3}' "$PASSWD_FILE" | sort | uniq -c | awk '$1 > 1 {print $2}' | while read -r uid; do
 echo "Duplicate UID: $uid"
 grep -F ":$uid:" "$PASSWD_FILE"
done
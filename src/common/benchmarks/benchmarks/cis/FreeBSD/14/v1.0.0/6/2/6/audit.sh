#!/bin/sh
PASSWD_FILE="/etc/passwd"

awk -F: '{print $1}' "$PASSWD_FILE" | sort | uniq -c | awk '$1 > 1 {print $2}' | while read -r username; do
 echo "Duplicate username: $username"
 grep -F "^$username:" "$PASSWD_FILE"
done
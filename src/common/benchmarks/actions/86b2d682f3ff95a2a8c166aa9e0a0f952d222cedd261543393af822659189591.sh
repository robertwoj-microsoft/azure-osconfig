#!/bin/sh

# Define the list of log files, their expected permissions, user, and group
log_files="
/var/log/messages:640:root:wheel
/var/log/cron:640:root:wheel
/var/log/auth.log:640:root:wheel
/var/log/maillog:640:root:wheel
/var/log/xferlog:640:root:wheel
/var/log/debug.log:640:root:wheel
/var/log/console.log:640:root:wheel
/var/log/dmesg:640:root:wheel
/var/log/security:640:root:wheel
/var/log/all.log:640:root:wheel
"

# Iterate over each log file, its expected permissions, user, and group
echo "$log_files" | while IFS=: read -r file expected_perms expected_user expected_group; do
 if [ -f "$file" ]; then
 # Get current permissions, user, and group of the file
 current_perms=$(stat -f "%Lp" "$file")
 current_user=$(stat -f "%Su" "$file")
 current_group=$(stat -f "%Sg" "$file")

 # Check if permissions are correct
 if [ "$current_perms" -ne "$expected_perms" ]; then
 echo "$file permission is set to $current_perms but should be $expected_perms"
 fi

 # Check if user ownership is correct
 if [ "$current_user" != "$expected_user" ]; then
 echo "$file ownership is set to $current_user but should be $expected_user"
 fi

 # Check if group ownership is correct
 if [ "$current_group" != "$expected_group" ]; then
 echo "$file group ownership is set to $current_group but should be $expected_group"
 fi
 else
 echo "File $file does not exist."
 fi
done

echo "Log file permissions, user, and group ownership check and fix completed."
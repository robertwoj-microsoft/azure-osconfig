#!/bin/sh

# Check if a user's home directory exists
check_home_directory() {
 local username=$1
 local homedir=$2

 if [ ! -d "$homedir" ]; then
 echo "Warning: Home directory $homedir does not exist for user $username"
 return 1
 fi
 return 0
}

# Check if the user owns their home directory
check_home_ownership() {
 local username=$1
 local homedir=$2

 if [ "$(stat -L -f '%Su' "$homedir")" != "$username" ]; then
 echo "Warning: User $username does not own their home directory $homedir"
 return 1
 fi
 return 0
}

# Check if the user's primary GID owns their home directory
check_home_group_ownership() {
 local gid=$1
 local homedir=$2

 if [ "$(stat -L -f '%Sg' "$homedir")" != "$(getent group "$gid" | cut -d: -f1)" ]; then
 echo "Warning: The primary group ID $gid does not own the home directory $homedir"
 return 1
 fi
 return 0
}

# Check if the home directory permissions are 0755 or more restrictive
check_home_permissions() {
 local homedir=$1

 if [ "$(stat -L -f '%Lp' "$homedir")" -gt 755 ]; then
 echo "Warning: Home directory $homedir has permissions more permissive than 0755"
 return 1
 fi
 return 0
}

# Get a list of all local interactive users
get_local_interactive_users() {
 awk -F: '($3 >= 1000 && $3 < 65534) && $7 != "/sbin/nologin" && $7 != "/bin/false" {print $1":"$6":"$4}' /etc/passwd
}

# Main script execution
for user_info in $(get_local_interactive_users); do
 username=$(echo "$user_info" | cut -d: -f1)
 homedir=$(echo "$user_info" | cut -d: -f2)
 gid=$(echo "$user_info" | cut -d: -f3)

 check_home_directory "$username" "$homedir"
 check_home_ownership "$username" "$homedir"
 check_home_group_ownership "$gid" "$homedir"
 check_home_permissions "$homedir"
done
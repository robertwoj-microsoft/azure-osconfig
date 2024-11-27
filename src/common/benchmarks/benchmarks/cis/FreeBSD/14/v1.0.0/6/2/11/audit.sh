#!/bin/sh

# Function to check file permissions
check_file_permissions() {
 local filepath=$1
 local required_mode=$2
 local current_mode

 current_mode=$(stat -f '%Lp' "$filepath")
 if [ "$current_mode" -gt "$required_mode" ]; then
 echo "Warning: $filepath has permissions more permissive than $required_mode"
 fi
}

# Function to check file ownership
check_file_ownership() {
 local filepath=$1
 local username=$2
 local gid=$3

 if [ "$(stat -f '%Su' "$filepath")" != "$username" ]; then
 echo "Warning: $filepath is not owned by $username"
 fi

 if [ "$(stat -f '%Sg' "$filepath")" != "$(getent group "$gid" | cut -d: -f1)" ]; then
 echo "Warning: The primary group ID $gid does not own $filepath"
 fi
}

# Function to verify dot files for a user
verify_dot_files() {
 local username=$1
 local homedir=$2
 local gid=$3

 for file in "$homedir"/.[!.]*; do
 [ -e "$file" ] || continue # Skip if the file does not exist

 # Exclude .forward, .rhost, .netrc
 case "$(basename "$file")" in
 .forward|.rhost|.netrc)
 echo "Warning: $file should not exist"
 ;;
 .sh_history)
 check_file_permissions "$file" 600
 ;;
 .history)
 check_file_permissions "$file" 600
 ;;
 *)
 check_file_permissions "$file" 644
 ;;
 esac

 # Check ownership for all other files
 check_file_ownership "$file" "$username" "$gid"
 done
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

 [ -d "$homedir" ] && verify_dot_files "$username" "$homedir" "$gid"
done
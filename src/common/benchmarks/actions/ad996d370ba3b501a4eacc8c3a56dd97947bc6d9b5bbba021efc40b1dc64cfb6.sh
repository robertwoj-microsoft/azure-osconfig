#!/bin/sh

# Function to check if a path is valid
check_path() {
 path=$1

 # Check if path is empty (i.e., "::" in the PATH variable)
 if [ -z "$path" ]; then
 echo "Warning: PATH contains an empty directory (::)"
 return 1
 fi

 # Check if path exists and is a directory
 if [ ! -d "$path" ]; then
 echo "Warning: $path is not a directory"
 return 1
 fi

 # Check if path is the current working directory (.)
 if [ "$path" = "." ]; then
 echo "Warning: PATH contains the current working directory (.)"
 return 1
 fi

 # Check if the directory is owned by root
 #if [ "$(stat -c '%U' "$path")" != "root" ]; then
 if [ "$(stat -L -f '%Su' "$path")" != "root" ]; then
 echo "Warning: $path is not owned by root"
 return 1
 fi

 # Check if the directory has permissions more permissive than 0755
 if [ "$(stat -L -f '%Lp' "$path")" -gt 755 ]; then
 echo "Warning: $path has permissions more permissive than 0755"
 return 1
 fi

 return 0
}

# Ensure the script is being run as root
if [ "$(id -u)" -ne 0 ]; then
 echo "This script must be run as root."
 exit 1
fi

# Check if the PATH ends with a trailing colon
if [ "${PATH%:}" != "$PATH" ]; then
 echo "Warning: PATH has a trailing colon (:)"
fi

# Split PATH by colon and check each entry
IFS=: # Set Internal Field Separator to colon
for dir in $PATH; do
 check_path "$dir"
done
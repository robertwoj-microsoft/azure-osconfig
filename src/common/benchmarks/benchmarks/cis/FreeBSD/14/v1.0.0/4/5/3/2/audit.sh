#!/bin/sh

# Files to check
files="/etc/login.conf /etc/profile.d/* /etc/csh.cshrc"

# Pattern to search for (umask 022 or 22)
pattern="umask.*0?22"

# Iterate over each file
for file in $files; do
 if [ -f "$file" ]; then
 # Check if the umask is set to 022 or 22 in the file
 if grep -qE "$pattern" "$file"; then
 echo "Correct umask (022 or 22) found in $file"
 else
 echo "WARNING: Correct umask (022 or 22) not found in $file"
 fi
 else
 echo "File $file does not exist."
 fi
done
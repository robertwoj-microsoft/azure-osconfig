#!/bin/bash

awk -F: '($1!~/(halt|sync|shutdown)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ -d "$dir" ]; then
 file="$dir/.netrc"
 if [ ! -h "$file" ] & then
 if stat -L -c "%A" "$file" | cut -c4-10 | grep -Eq '[^-]+'; then
 echo "FAILED: User: \"$user\" file: \"$file\" exists with permissions: \"$(stat -L -c "%a" "$file")\", remove file or excessive permissions"
 else
 echo "WARNING: User: \"$user\" file: \"$file\" exists with permissions: \"$(stat -L -c "%a" "$file")\", remove file unless required"
 fi
 fi
 fi
done
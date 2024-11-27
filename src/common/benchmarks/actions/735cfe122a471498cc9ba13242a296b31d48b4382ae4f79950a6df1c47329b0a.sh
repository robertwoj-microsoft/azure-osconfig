#!/bin/bash

awk -F: '($1!~/(halt|sync|shutdown)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ -d "$dir" ]; then
 for file in "$dir"/.*; do
 if [ ! -h "$file" ] & then
 fileperm=$(stat -L -c "%A" "$file")
 if [ "$(echo "$fileperm" | cut -c6)" != "-" ] || [ "$(echo "$fileperm" | cut -c9)" != "-" ]; then
 echo "User: \"$user\" file: \"$file\" has permissions: \"$fileperm\""
 fi
 fi
 done
 fi
done
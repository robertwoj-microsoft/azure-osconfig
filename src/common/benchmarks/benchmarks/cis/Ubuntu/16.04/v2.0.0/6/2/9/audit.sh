#!/bin/bash 

awk -F: '($1!~/(root|halt|sync|shutdown)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ -d "$dir" ]; then
 file="$dir/.forward"
 if [ ! -h "$file" ] & then 
 echo "User: \"$user\" file: \"$file\" exists"
 fi
 fi
done
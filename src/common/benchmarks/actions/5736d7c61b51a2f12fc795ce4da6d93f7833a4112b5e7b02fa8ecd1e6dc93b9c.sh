#!/bin/bash 

awk -F: '($1!~/(root|halt|sync|shutdown)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ -d "$dir" ]; then
 file="$dir/.rhosts"
 [ ! -h "$file" ] && [ -f "$file" ] && rm -r "$file"
 fi
done
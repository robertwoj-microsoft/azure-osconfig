#!/bin/bash

awk -F: '($1!~/(halt|sync|shutdown)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ -d "$dir" ]; then
 file="$dir/.netrc"
 [ ! -h "$file" ] && [ -f "$file" ] && rm -f "$file"
 fi
done
#!/bin/bash

awk -F: '($1!~/(halt|sync|shutdown|nfsnobody)/ && $7!~/^(\/usr)?\/sbin\/nologin(\/)?$/ & do
 if [ ! -d "$dir" ]; then
 mkdir "$dir"
 chmod g-w,o-wrx "$dir"
 chown "$user" "$dir"
 fi
done
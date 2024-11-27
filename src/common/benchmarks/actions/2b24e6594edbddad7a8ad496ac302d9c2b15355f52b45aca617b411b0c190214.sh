#!/usr/bin/env bash

{
 for i in $(cut -s -d: -f4 /etc/passwd | sort -u ); do
 grep -Pq -- "^.*?:[^:]*:$i:" /etc/group
 if [ $? -ne 0 ]; then
 echo "Group $i is referenced by /etc/passwd but does not exist in /etc/group"
 fi
 done
}
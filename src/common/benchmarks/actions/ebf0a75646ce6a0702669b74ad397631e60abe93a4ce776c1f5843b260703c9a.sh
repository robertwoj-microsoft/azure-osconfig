#!/usr/bin/env bash

{
 if dpkg-query -W at > /dev/null 2> then
 l_file="/etc/at.allow"
 l_mask='0137'
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_mask)) )"
 if [ -e /etc/at.deny ]; then
 echo -e " - Removing \"/etc/at.deny\""
 rm -f /etc/at.deny
 fi
 if [ ! -e /etc/at.allow ]; then
 echo -e " - creating \"$l_file\""
 touch "$l_file"
 fi
 while read l_mode l_fown l_fgroup; do
 if [ $(( $l_mode & $l_mask )) -gt 0 ]; then
 echo -e " - Removing excessive permissions from \"$l_file\""
 chmod u-x,g-wx,o-rwx "$l_file"
 fi
 if [ "$l_fown" != "root" ]; then
 echo -e " - Changing owner on \"$l_file\" from: \"$l_fown\" to: \"root\""
 chown root "$l_file"
 fi
 if [ "$l_fgroup" != "root" ]; then
 echo -e " - Changing group owner on \"$l_file\" from: \"$l_fgroup\" to: \"root\""
 chgrp root "$l_file"
 fi
 done < <(stat -Lc '%#a %U %G' "$l_file")
 else
 echo -e "- cron is not installed on the system, no remediation required\n"
 fi
}
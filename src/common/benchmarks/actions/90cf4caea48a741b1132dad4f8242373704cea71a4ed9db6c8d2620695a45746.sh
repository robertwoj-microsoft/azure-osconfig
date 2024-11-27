#!/usr/bin/env bash

{
 l_output="" l_output2=""
 if dpkg-query -W cron > /dev/null 2> then
 l_file="/etc/cron.allow"
 [ -e /etc/cron.deny ] && l_output2="$l_output2\n - cron.deny exists"
 if [ ! -e /etc/cron.allow ]; then 
 l_output2="$l_output2\n - cron.allow doesn't exist"
 else
 l_mask='0137'
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_mask)) )"
 while read l_mode l_fown l_fgroup; do 
 if [ $(( $l_mode & $l_mask )) -gt 0 ]; then
 l_output2="$l_output2\n - \"$l_file\" is mode: \"$l_mode\" (should be mode: \"$l_maxperm\" or more restrictive)"
 else
 l_output="$l_output\n - \"$l_file\" is correctly set to mode: \"$l_mode\""
 fi
 if [ "$l_fown" != "root" ]; then
 l_output2="$l_output2\n - \"$l_file\" is owned by user \"$l_fown\" (should be owned by \"root\")"
 else
 l_output="$l_output\n - \"$l_file\" is correctly owned by user: \"$l_fown\""
 fi
 if [ "$l_fgroup" != "crontab" ]; then
 l_output2="$l_output2\n - \"$l_file\" is owned by group: \"$l_fgroup\" (should be owned by group: \"crontab\")"
 else
 l_output="$l_output\n - \"$l_file\" is correctly owned by group: \"$l_fgroup\""
 fi
 done < <(stat -Lc '%#a %U %G' "$l_file")
 fi
 else
 l_output="$l_output\n - cron is not installed on the system"
 fi
 if [ -z "$l_output2" ]; then
 echo -e "\n- Audit Result:\n ** PASS **$l_output\n"
 else
 echo -e "\n- Audit Result:\n ** FAIL **\n - Reason(s) for audit failure:$l_output2\n"
 fi
}
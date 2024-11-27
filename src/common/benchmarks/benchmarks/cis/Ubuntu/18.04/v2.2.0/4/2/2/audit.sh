#!/usr/bin/env bash

{
 l_output="" l_output2="" l_count="0"
 if command -v ssh-keygen &>/dev/null; then
 if [ -d /etc/ssh ]; then
 l_ssh_key_group_name="$(grep -Po -- '^(ssh_keys|_?ssh)\b' /etc/group)" # Group designated to own openSSH keys
 f_key_chk()
 {
 l_out2=""
 while IFS=: read -r l_mode l_owner l_group; do
 if [ "$l_key_type" = "public" ]; then
 l_pmask="0133"
 l_auth_group="root"
 else
 [ "$l_ssh_key_group_name" = "$l_group" ] && l_pmask="0137" || l_pmask="0177"
 [ -n "$l_ssh_key_group_name" ] && l_auth_group="(root|$l_ssh_key_group_name)" || l_auth_group="root"
 fi
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_pmask )) )"
 if [ $(( $l_mode & $l_pmask )) -gt 0 ]; then
 l_out2="$l_out2\n - Mode: \"$l_mode\" should be mode: \"$l_maxperm\" or more restrictive"
 fi
 if [ "$l_owner" != "root" ]; then
 l_out2="$l_out2\n - Owned by: \"$l_owner\" should be owned by \"root\""
 fi
 if [[ ! "$l_group" =~ $l_auth_group ]]; then
 l_out2="$l_out2\n - Owned by group \"$l_group\" should be group owned by: \" ${l_auth_group//|/ or } \""
 fi
 if [ -n "$l_out2" ]; then
 l_output2="$l_output2\n - $l_key_type key file: \"$l_file\"$l_out2"
 else
 l_output="$l_output\n - $l_key_type key file: \"$l_file\"\n - Correct: mode ($l_mode), owner ($l_owner), and group owner ($l_group) configured"
 fi
 done < <(stat -Lc '%#a:%U:%G' "$l_file")
 }
 while IFS= read -r -d $'\0' l_file; do # Loop to populate array
 if ssh-keygen -l -f "$l_file" &>/dev/null; then
 (( l_count++ ))
 if grep -Pq -- '\.pub$' <<< "$l_file"; then
 l_key_type="public"
 else
 l_key_type="private" 
 fi
 f_key_chk
 fi
 done < <(find /etc/ssh -xdev -type f -print0)
 [ "$l_count" = "0" ] && l_output=" - No ssh keys found in \"/etc/ssh\""
 else
 l_output=" - ssh directory: \"/etc/ssh\" not found on the system"
 fi
 else
 l_output2=" - ssh-keygen command not found\n - manual check may be required"
 fi
 if [ -z "$l_output2" ]; then
 echo -e "\n- Audit Result:\n *** PASS ***\n- * Correctly set * :\n$l_output\n"
 else
 echo -e "\n- Audit Result:\n ** FAIL **\n - * Reasons for audit failure * :\n$l_output2\n"
 [ -n "$l_output" ] && echo -e " - * Correctly set * :\n$l_output\n"
 fi
}
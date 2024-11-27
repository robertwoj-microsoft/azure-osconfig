#!/usr/bin/env bash

{
 l_output="" l_output2="" l_count="0"
 if command -v ssh-keygen &>/dev/null; then
 if [ -d /etc/ssh ]; then
 l_ssh_key_group_name="$(grep -Po -- '^(ssh_keys|_?ssh)\b' /etc/group)" # Group designated to own openSSH keys
 f_key_fix()
 {
 while IFS=: read -r l_mode l_owner l_group; do
 if [ "$l_key_type" = "public" ]; then
 l_pmask="0133" && l_mode_fix="u-x,go-wx"
 l_auth_group="root" && l_group_fix="root"
 else
 if [ "$l_ssh_key_group_name" = "$l_group" ]; then
 l_pmask="0137" && l_mode_fix="u-x,g-wx,o-rwx"
 else
 l_pmask="0177" && l_mode_fix="u-x,go-rwx"
 fi
 if [ -n "$l_ssh_key_group_name" ]; then
 l_auth_group="(root|$l_ssh_key_group_name)" && l_group_fix="$l_ssh_key_group_name"
 else
 l_auth_group="root" && l_group_fix="root"
 fi
 fi
 if [ "$l_owner" != "root" ]; then
 echo -e "\n - $l_key_type key file: \"$l_file\" - Owned by: \"$l_owner\" changing owner to: \"root\""
 chown root "$l_file"
 fi
 if [[ ! "$l_group" =~ $l_auth_group ]]; then
 echo -e "\n - $l_key_type key file: \"$l_file\"\n - Owned by group \"$l_group\" changing group owner to: \"$l_group_fix\""
 chgrp "$l_group_fix" "$l_file"
 fi
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_pmask )) )"
 if [ $(( $l_mode & $l_pmask )) -gt 0 ]; then
 echo -e "\n - $l_key_type key file: \"$l_file\"\n - Mode: \"$l_mode\" removing excessive permissions"
 chmod "$l_mode_fix" "$l_file"
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
 f_key_fix
 fi
 done < <(find /etc/ssh -xdev -type f -print0)
 [ "$l_count" = "0" ] && echo " - No ssh keys found in \"/etc/ssh\""
 else
 echo " - ssh directory: \"/etc/ssh\" not found on the system"
 fi
 else
 echo -e " - ssh-keygen command not found\n - manual remediation may be required"
 fi
}
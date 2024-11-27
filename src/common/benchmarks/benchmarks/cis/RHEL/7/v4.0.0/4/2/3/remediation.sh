#!/usr/bin/env bash

{
 l_output="" l_output2=""
 l_skgn="$(grep -Po -- '^(ssh_keys|_?ssh)\b' /etc/group)" # Group designated to own openSSH keys
 l_skgid="$(awk -F: '($1 == "'"$l_skgn"'"){print $3}' /etc/group)" # Get gid of group
 l_mfix="u-x,go-wx"
 if command -v ssh-keygen &>/dev/null; then
 unset a_skarr && a_skarr=() # Clear and initialize array
 if [ -d /etc/ssh ]; then
 while IFS= read -r -d $'\0' l_file; do # Loop to populate array
 if grep -Pq -- '\h+no\h+comment\b' <<< "$(ssh-keygen -l -f 2>/dev/null "$l_file")"; then
 a_skarr+=("$(stat -Lc '%n^%#a^%U^%G^%g' "$l_file")")
 fi
 done < <(find -L /etc/ssh -xdev -type f -print0)
 if (( ${#a_skarr[@]} > 0 )); then
 while IFS="^" read -r l_file l_mode l_owner l_group l_gid; do
 l_out2=""
 l_pmask="0133"
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_pmask )) )"
 if [ $(( $l_mode & $l_pmask )) -gt 0 ]; then
 l_out2="$l_out2\n - Mode: \"$l_mode\" should be mode: \"$l_maxperm\" or more restrictive\n - Revoking excess permissions"
 chmod "$l_mfix" "$l_file"
 fi
 if [ "$l_owner" != "root" ]; then
 l_out2="$l_out2\n - Owned by: \"$l_owner\" should be owned by \"root\"\n - Changing ownership to \"root\""
 chown root "$l_file"
 fi
 if [[ ! "$l_group" =~ $l_agroup ]]; then
 l_out2="$l_out2\n - Owned by group \"$l_group\" should be group owned by: \"${l_agroup//|/ or }\"\n - Changing group ownership to \"$l_sgroup\""
 chgrp "$l_sgroup" "$l_file"
 fi
 [ -n "$l_out2" ] && l_output2="$l_output2\n - File: \"$l_file\"$l_out2"
 done <<< "$(printf '%s\n' "${a_skarr[@]}")"
 else
 l_output=" - No public keys found in \"/etc/ssh\""
 fi
 else
 l_output="- ssh directory not found on the system"
 fi
 unset a_skarr
 else
 l_output2=" - ssh-keygen command not found\n - manual remediation may be required"
 fi
 if [ -z "$l_output2" ]; then
 echo -e "\n- No access changes required\n"
 else
 echo -e "\n- Remediation results:\n$l_output2\n"
 fi
}
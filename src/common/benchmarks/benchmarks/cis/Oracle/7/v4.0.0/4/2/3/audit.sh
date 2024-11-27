#!/usr/bin/env bash

{
 l_output="" l_output2=""
 l_skgn="$(grep -Po -- '^(ssh_keys|_?ssh)\b' /etc/group)" # Group designated to own openSSH public keys
 l_skgid="$(awk -F: '($1 == "'"$l_skgn"'"){print $3}' /etc/group)" # Get gid of group
 [ -n "$l_skgid" ] && l_agroup="(root|$l_skgn)" || l_agroup="root"
 if command -v ssh-keygen &>/dev/null; then
 unset a_skarr && a_skarr=() # Clear and initialize array
 if [ -d "/etc/ssh" ]; then
 while IFS= read -r -d $'\0' l_file; do # Loop to populate array
 if grep -Pq -- '\h+no\h+comment\b' <<< "$(ssh-keygen -l -f 2>/dev/null "$l_file")"; then
 a_skarr+=("$(stat -Lc '%n^%#a^%U^%G^%g' "$l_file")")
 fi
 done < <(find -L /etc/ssh -xdev -type f -print0)
 if (( ${#a_skarr[@]} > 0 )); then
 while IFS="^" read -r l_file l_mode l_owner l_group l_gid; do
 echo "File: \"$l_file\" Mode: \"$l_mode\" Owner: \"$l_owner\" Group: \"$l_group\" GID: \"$l_gid\""
 l_out2=""
 l_pmask="0133"
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_pmask )) )"
 if [ $(( $l_mode & $l_pmask )) -gt 0 ]; then
 l_out2="$l_out2\n - Mode: \"$l_mode\" should be mode: \"$l_maxperm\" or more restrictive"
 fi
 if [ "$l_owner" != "root" ]; then
 l_out2="$l_out2\n - Owned by: \"$l_owner\" should be owned by \"root\""
 fi
 if [[ ! "$l_group" =~ $l_agroup ]]; then
 l_out2="$l_out2\n - Owned by group \"$l_group\" should be group owned by: \"${l_agroup//|/ or }\""
 fi
 if [ -n "$l_out2" ]; then
 l_output2="$l_output2\n - File: \"$l_file\"$l_out2"
 else
 l_output="$l_output\n - File: \"$l_file\"\n - Correct: mode ($l_mode), owner ($l_owner), and group owner ($l_group) configured"
 fi
 done <<< "$(printf '%s\n' "${a_skarr[@]}")"
 else
 l_output=" - No public keys found in \"/etc/ssh\""
 fi
 else
 l_output="- ssh directory not found on the system"
 fi
 unset a_skarr
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
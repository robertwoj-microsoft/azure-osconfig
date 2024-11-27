#!/usr/bin/env bash

{
 a_output=(); a_output2=()
 perm_mask='0177' && maxperm="$( printf '%o' $(( 0777 & ~$perm_mask)) )"
 f_sshd_files_chk()
 {
 while IFS=: read -r l_mode l_user l_group; do
 a_out2=()
 [ $(( $l_mode & $perm_mask )) -gt 0 ] && a_out2+=(" Is mode: \"$l_mode\"" \
 " should be mode: \"$maxperm\" or more restrictive")
 [ "$l_user" != "root" ] && a_out2+=(" Is owned by \"$l_user\" should be owned by \"root\"")
 [ "$l_group" != "root" ] && a_out2+=(" Is group owned by \"$l_user\" should be group owned by \"root\"")
 if [ "${#a_out2[@]}" -gt "0" ]; then
 a_output2+=(" - File: \"$l_file\":" "${a_out2[@]}")
 else
 a_output+=(" - File: \"$l_file\":" " Correct: mode ($l_mode), owner ($l_user)" \
 " and group owner ($l_group) configured")
 fi
 done < <(stat -Lc '%#a:%U:%G' "$l_file") 
 }
 [ -e "/etc/ssh/sshd_config" ] && l_file="/etc/ssh/sshd_config" && f_sshd_files_chk
 while IFS= read -r -d $'\0' l_file; do
 [ -e "$l_file" ] && f_sshd_files_chk
 done < <(find /etc/ssh/sshd_config.d -type f -name '*.conf' \( -perm /077 -o ! -user root -o ! -group root \) -print0 2>/dev/null)
 if [ "${#a_output2[@]}" -le 0 ]; then
 printf '%s\n' "" "- Audit Result:" " ** PASS **" "${a_output[@]}" ""
 else
 printf '%s\n' "" "- Audit Result:" " ** FAIL **" " - Reason(s) for audit failure:" "${a_output2[@]}"
 [ "${#a_output[@]}" -gt 0 ] && printf '%s\n' "" "- Correctly set:" "${a_output[@]}" ""
 fi
}
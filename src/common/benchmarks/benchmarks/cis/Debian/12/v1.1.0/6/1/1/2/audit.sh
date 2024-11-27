#!/usr/bin/env bash

{
 a_output=() a_output2=()
 l_systemd_config_file="/etc/tmpfiles.d/systemd.conf" l_analyze_cmd="$(readlink -f /bin/systemd-analyze)"
 f_file_chk()
 {
 l_maxperm="$( printf '%o' $(( 0777 & ~$l_perm_mask )) )"
 if [ $(( $l_mode & $l_perm_mask )) -le 0 ] || [[ "$l_type" = "Directory" && "$l_mode" =~ 275(0|5) ]]; then
 a_out+=(" - $l_type \"$l_logfile\" access is:" \
 " mode: \"$l_mode\", owned by: \"$l_user\", and group owned by: \"$l_group\"")
 else
 a_out2+=(" - $l_type \"$l_logfile\" access is:" \
 " mode: \"$l_mode\", owned by: \"$l_user\", and group owned by: \"$l_group\"" \
 " should be mode: \"$l_maxperm\" or more restrictive")
 fi
 }
 while IFS= read -r l_file; do
 l_file="$(tr -d '# ' <<< "$l_file")" a_out=() a_out2=()
 l_logfile_perms_line="$(awk '($1~/^(f|d)$/ && $2~/\/\S+/ && $3~/[0-9]{3,}/){print $2 ":" $3 ":" $4 ":" $5}' "$l_file")"
 while IFS=: read -r l_logfile l_mode l_user l_group; do
 if [ -d "$l_logfile" ]; then
 l_perm_mask="0027" l_type="Directory"
 grep -Psq '^(\/run|\/var\/lib\/systemd)\b' <<< "$l_logfile" && l_perm_mask="0022"
 else
 l_perm_mask="0137" l_type="File"
 fi
 grep -Psq '^(\/run|\/var\/lib\/systemd)\b' <<< "$l_logfile" && l_perm_mask="0022"
 f_file_chk
 done <<< "$l_logfile_perms_line"
 [ "${#a_out[@]}" -gt "0" ] && a_output+=(" - File: \"$l_file\" sets:" "${a_out[@]}")
 [ "${#a_out2[@]}" -gt "0" ] && a_output2+=(" - File: \"$l_file\" sets:" "${a_out2[@]}")
 done < <($l_analyze_cmd cat-config "$l_systemd_config_file" | tac | grep -Pio '^\h*#\h*\/[^#\n\r\h]+\.conf\b')
 if [ "${#a_output2[@]}" -le 0 ]; then
 printf '%s\n' "" "- Audit Result:" " ** PASS **" "${a_output[@]}" ""
 else
 printf '%s\n' "" "- Audit Result:" " ** REVIEW **" \
 " - Review file access to ensure they are set IAW site policy:" "${a_output2[@]}"
 [ "${#a_output[@]}" -gt 0 ] && printf '%s\n' "" "- Correctly set:" "${a_output[@]}" ""
 fi 
}
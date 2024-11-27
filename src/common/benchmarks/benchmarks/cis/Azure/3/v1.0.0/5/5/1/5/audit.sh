{
 l_output2=""
 while read -r l_user; do
 l_change="$(chage --list $l_user | awk -F: '($1 ~ /^\s*Last\s+password\s+change/ && $2 !~ /never/){print $2}' | xargs)"
 if [[ "$(date -d "$l_change" +%s)" -gt "$(date +%s)" ]]; then
 l_output2="$l_output2\n - User: \"$l_user\" last password change is in the future \"$l_change\""
 fi
 done < <(awk -F: '($2 ~ /^[^*!xX\n\r][^\n\r]+/){print $1}' /etc/shadow)
 if [ -z "$l_output2" ]; then # If l_output2 is empty, we pass
 echo -e "\n- Audit Result:\n ** PASS **\n - All user password changes are in the past \n"
 else
 echo -e "\n- Audit Result:\n ** FAIL **\n - * Reasons for audit failure * :$l_output2\n"
 fi
}
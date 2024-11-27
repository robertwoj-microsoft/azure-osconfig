#!/usr/bin/env bash

{
 a_output=(); a_output2=()
 f_file_test_chk()
 {
 a_out2=() 
 maxperm="$( printf '%o' $(( 0777 & ~$perm_mask)) )"
 [ $(( $l_mode & $perm_mask )) -gt 0 ] && \
 a_out2+=(" o Mode: \"$l_mode\" should be \"$maxperm\" or more restrictive")
 [[ ! "$l_user" =~ $l_auser ]] && \
 a_out2+=(" o Owned by: \"$l_user\" and should be owned by \"${l_auser//|/ or }\"")
 [[ ! "$l_group" =~ $l_agroup ]] && \
 a_out2+=(" o Group owned by: \"$l_group\" and should be group owned by \"${l_agroup//|/ or }\"")
 [ "${#a_out2[@]}" -gt 0 ] && a_output2+=(" - File: \"$l_fname\" is:" "${a_out2[@]}")
 }
 while IFS= read -r -d $'\0' l_file; do
 while IFS=: read -r l_fname l_mode l_user l_group; do
 if grep -Pq -- '\/(apt)\h*$' <<< "$(dirname "$l_fname")"; then
 perm_mask='0133' l_auser="root" l_agroup="(root|adm)"; f_file_test_chk
 else
 case "$(basename "$l_fname")" in
 lastlog | lastlog.* | wtmp | wtmp.* | wtmp-* | btmp | btmp.* | btmp-* | README)
 perm_mask='0113' l_auser="root" l_agroup="(root|utmp)"
 f_file_test_chk ;;
 cloud-init.log* | localmessages* | waagent.log*)
 perm_mask='0133' l_auser="(root|syslog)" l_agroup="(root|adm)"
 f_file_test_chk ;;
 secure{,*.*,.*,-*} | auth.log | syslog | messages)
 perm_mask='0137' l_auser="(root|syslog)" l_agroup="(root|adm)"
 f_file_test_chk ;;
 SSSD | sssd)
 perm_mask='0117' l_auser="(root|SSSD)" l_agroup="(root|SSSD)"
 f_file_test_chk ;;
 gdm | gdm3)
 perm_mask='0117' l_auser="root" l_agroup="(root|gdm|gdm3)"
 f_file_test_chk ;;
 *.journal | *.journal~)
 perm_mask='0137' l_auser="root" l_agroup="(root|systemd-journal)"
 f_file_test_chk ;;
 *)
 perm_mask='0137' l_auser="(root|syslog)" l_agroup="(root|adm)"
 if [ "$l_user" = "root" ] || ! grep -Pq -- "^\h*$(awk -F: '$1=="'"$l_user"'" {print $7}' /etc/passwd)\b" /etc/shells; then
 ! grep -Pq -- "$l_auser" <<< "$l_user" && l_auser="(root|syslog|$l_user)"
 ! grep -Pq -- "$l_agroup" <<< "$l_group" && l_agroup="(root|adm|$l_group)"
 fi
 f_file_test_chk ;;
 esac
 fi
 done < <(stat -Lc '%n:%#a:%U:%G' "$l_file")
 done < <(find -L /var/log -type f \( -perm /0137 -o ! -user root -o ! -group root \) -print0)
 if [ "${#a_output2[@]}" -le 0 ]; then
 a_output+=(" - All files in \"/var/log/\" have appropriate permissions and ownership")
 printf '\n%s' "- Audit Result:" " ** PASS **" "${a_output[@]}" ""
 else
 printf '\n%s' "- Audit Result:" " ** FAIL **" " - Reason(s) for audit failure:" "${a_output2[@]}" ""
 fi
}
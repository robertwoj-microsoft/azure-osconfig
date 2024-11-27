#!/usr/bin/env bash

{
 l_output="" l_output2=""
 l_valid_shells="^($( awk -F\/ '$NF != "nologin" {print}' /etc/shells | sed -rn '/^\//{s,/,\\\\/,g;p}' | paste -s -d '|' - ))$"
 a_users=(); a_ulock=() # initialize arrays
 while read -r l_user; do # Populate array with system accounts that have a valid login shell
 a_users+=("$l_user")
 done < <(awk -v pat="$l_valid_shells" -F: '($1!~/(root|sync|shutdown|halt|^\+)/ && $3<'"$(awk '/^\s*UID_MIN/{print $2}' /etc/login.defs)"' && $(NF) ~ pat) { print $1 }' /etc/passwd)
 while read -r l_ulock; do # Populate array with system accounts that aren't locked
 a_ulock+=("$l_ulock")
 done < <(awk -v pat="$l_valid_shells" -F: '($1!~/(root|^\+)/ && $2!~/LK?/ && $3<'"$(awk '/^\s*UID_MIN/{print $2}' /etc/login.defs)"' && $(NF) ~ pat) { print $1 }' /etc/passwd)
 if ! (( ${#a_users[@]} > 0 )); then
 l_output="$l_output\n - local system accounts login is disabled"
 else
 l_output2="$l_output2\n - There are \"$(printf '%s' "${#a_users[@]}")\" system accounts with login enabled\n - List of accounts:\n$(printf '%s\n' "${a_users[@]:0:$l_limit}")\n - end of list\n"
 fi
 if ! (( ${#a_ulock[@]} > 0 )); then
 l_output="$l_output\n - local system accounts are locked"
 else
 l_output2="$l_output2\n - There are \"$(printf '%s' "${#a_ulock[@]}")\" system accounts that are not locked\n - List of accounts:\n$(printf '%s\n' "${a_ulock[@]:0:$l_limit}")\n - end of list\n"
 fi
 unset a_users; unset a_ulock # Remove arrays
 if [ -z "$l_output2" ]; then
 echo -e "\n- Audit Result:\n ** PASS **\n - * Correctly configured * :\n$l_output\n"
 else
 echo -e "\n- Audit Result:\n ** FAIL **\n - * Reasons for audit failure * :\n$l_output2"
 [ -n "$l_output" ] && echo -e "- * Correctly configured * :\n$l_output\n"
 fi
}
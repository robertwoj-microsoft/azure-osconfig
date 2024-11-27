#!/usr/bin/env bash

{
 a_output=(); a_output2=(); a_parlist=("NTP=[^#\n\r]+" "FallbackNTP=[^#\n\r]+")
 l_systemd_config_file="/etc/systemd/timesyncd.conf" # Main systemd configuration file
 f_config_file_parameter_chk()
 {
 unset A_out; declare -A A_out # Check config file(s) setting
 while read -r l_out; do
 if [ -n "$l_out" ]; then
 if [[ $l_out =~ ^\s*# ]]; then
 l_file="${l_out//# /}"
 else
 l_systemd_parameter="$(awk -F= '{print $1}' <<< "$l_out" | xargs)"
 grep -Piq -- "^\h*$l_systemd_parameter_name\b" <<< "$l_systemd_parameter" && A_out+=(["$l_systemd_parameter"]="$l_file")
 fi
 fi
 done < <("$l_systemdanalyze" cat-config "$l_systemd_config_file" | grep -Pio '^\h*([^#\n\r]+|#\h*\/[^#\n\r\h]+\.conf\b)')
 if (( ${#A_out[@]} > 0 )); then # Assess output from files and generate output
 while IFS="=" read -r l_systemd_file_parameter_name l_systemd_file_parameter_value; do
 l_systemd_file_parameter_name="${l_systemd_file_parameter_name// /}"
 l_systemd_file_parameter_value="${l_systemd_file_parameter_value// /}"
 if grep -Piq "\b$l_systemd_parameter_value\b" <<< "$l_systemd_file_parameter_value"; then
 a_output+=(" - \"$l_systemd_parameter_name\" is correctly set to \"$l_systemd_file_parameter_value\"" \
 " in \"$(printf '%s' "${A_out[@]}")\"")
 else
 a_output2+=(" - \"$l_systemd_parameter_name\" is incorrectly set to \"$l_systemd_file_parameter_value\"" \
 " in \"$(printf '%s' "${A_out[@]}")\" and should have a value matching: \"$l_value_out\"")
 fi
 done < <(grep -Pio -- "^\h*$l_systemd_parameter_name\h*=\h*\H+" "${A_out[@]}")
 else
 a_output2+=(" - \"$l_systemd_parameter_name\" is not set in an included file" \
 " *** Note: \"$l_systemd_parameter_name\" May be set in a file that's ignored by load procedure ***")
 fi
 }
 l_systemdanalyze="$(readlink -f /bin/systemd-analyze)"
 while IFS="=" read -r l_systemd_parameter_name l_systemd_parameter_value; do # Assess and check parameters
 l_systemd_parameter_name="${l_systemd_parameter_name// /}"; l_systemd_parameter_value="${l_systemd_parameter_value// /}"
 l_value_out="${l_systemd_parameter_value//-/ through }"; l_value_out="${l_value_out//|/ or }"
 l_value_out="$(tr -d '(){}' <<< "$l_value_out")"
 f_config_file_parameter_chk
 done < <(printf '%s\n' "${a_parlist[@]}")
 if [ "${#a_output2[@]}" -le 0 ]; then
 printf '%s\n' "" "- Audit Result:" " ** PASS **" "${a_output[@]}" ""
 else
 printf '%s\n' "" "- Audit Result:" " ** FAIL **" " - Reason(s) for audit failure:" "${a_output2[@]}"
 [ "${#a_output[@]}" -gt 0 ] && printf '%s\n' "" "- Correctly set:" "${a_output[@]}" ""
 fi
}
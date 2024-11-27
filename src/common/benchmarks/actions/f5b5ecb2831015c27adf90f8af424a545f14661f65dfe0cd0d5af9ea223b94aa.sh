#!/usr/bin/env bash

{
 a_output=() a_output2=() a_output3=() a_out=() a_out2=() a_parlist=("NTP=[^#\n\r]+" "FallbackNTP=[^#\n\r]+") 
 l_analyze_cmd="$(readlink -f /bin/systemd-analyze)" l_systemd_config_file="/etc/systemd/timesyncd.conf"
 f_config_file_parameter_chk()
 {
 l_used_parameter_setting=""
 while IFS= read -r l_file; do
 l_file="$(tr -d '# ' <<< "$l_file")"
 l_used_parameter_setting="$(grep -PHs -- '^\h*'"$l_parameter_name"'\b' "$l_file" | tail -n 1)"
 [ -n "$l_used_parameter_setting" ] && break
 done < <($l_analyze_cmd cat-config "$l_systemd_config_file" | tac | grep -Pio '^\h*#\h*\/[^#\n\r\h]+\.conf\b')
 if [ -n "$l_used_parameter_setting" ]; then
 while IFS=: read -r l_file_name l_file_parameter; do
 while IFS="=" read -r l_file_parameter_name l_file_parameter_value; do
 if grep -Pq -- "$l_parameter_value" <<< "$l_file_parameter_value"; then
 a_out+=(" - Parameter: \"${l_file_parameter_name// /}\"" \
 " correctly set to: \"${l_file_parameter_value// /}\"" \
 " in the file: \"$l_file_name\"")
 else
 a_out2+=(" - Parameter: \"${l_file_parameter_name// /}\"" \
 " incorrectly set to: \"${l_file_parameter_value// /}\"" \
 " in the file: \"$l_file_name\"" \
 " Should be set to: \"$l_value_out\"")
 fi
 done <<< "$l_file_parameter"
 done <<< "$l_used_parameter_setting"
 else
 a_out2+=(" - Parameter: \"$l_parameter_name\" is not set in an included file" \
 " *** Note: \"$l_parameter_name\" May be set in a file that's ignored by load procedure ***")
 fi
 }
 while IFS="=" read -r l_parameter_name l_parameter_value; do # Assess and check parameters
 l_parameter_name="${l_parameter_name// /}"; l_parameter_value="${l_parameter_value// /}"
 l_value_out="${l_parameter_value//-/ through }"; l_value_out="${l_value_out//|/ or }"
 l_value_out="$(tr -d '(){}' <<< "$l_value_out")"
 f_config_file_parameter_chk
 done < <(printf '%s\n' "${a_parlist[@]}")
 if [ "${#a_out[@]}" -gt 0 ]; then
 a_output+=("${a_out[@]}"); [ "${#a_out2[@]}" -gt 0 ] && a_output3+=(" ** INFO: **" "${a_out2[@]}")
 else
 a_output2+=("${a_out2[@]}")
 fi
 if [ "${#a_output2[@]}" -le 0 ]; then
 printf '%s\n' "" "- Audit Result:" " ** PASS **" "${a_output[@]}" ""
 [ "${#a_output3[@]}" -gt 0 ] && printf '%s\n' "${a_output3[@]}"
 else
 printf '%s\n' "" "- Audit Result:" " ** FAIL **" " - Reason(s) for audit failure:" "${a_output2[@]}"
 [ "${#a_output[@]}" -gt 0 ] && printf '%s\n' "" "- Correctly set:" "${a_output[@]}" ""
 fi
}
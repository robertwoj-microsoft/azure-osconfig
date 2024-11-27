#!/usr/bin/env bash

{
 l_output="" l_output2=""
 a_parlist=("net.ipv4.conf.all.rp_filter=1" "net.ipv4.conf.default.rp_filter=1")
 l_ufwscf="$([ -f /etc/default/ufw ] && awk -F= '/^\s*IPT_SYSCTL=/ {print $2}' /etc/default/ufw)"
 a_searchpath=("/run/sysctl.d/" "/etc/sysctl.d/" "/usr/local/lib/sysctl.d/" "/usr/lib/sysctl.d/" "/lib/sysctl.d/")
 unset A_files
 declare -A A_files # Array of "valid" files
 A_files+=(["sysctl.conf"]="/etc/sysctl.conf")
 for l_searchpath in "${a_searchpath[@]}"; do
 if [ -d "$l_searchpath" ]; then
 while IFS= read -r -d $'\0' l_filename; do
 if [ -f "$l_filename" ]; then
 l_basename="$(basename "$l_filename")"
 if [ -z "${A_files["$l_basename"]}" ]; then
 A_files+=(["$l_basename"]="$l_filename")
 fi
 fi
 done < <(find "$l_searchpath" -type f -name '*.conf' -print0)
 fi
 done
 a_sorted=()
 while IFS= read -rd '' l_key; do
 a_sorted+=( "$l_key" )
 done < <(printf '%s\0' "${!A_files[@]}" | sort -rz)
 kernel_parameter_chk()
 {
 l_var="" l_var2=""
 l_krp="$(sysctl "$l_kpname" | awk -F= '{print $2}' | xargs)" # Check running configuration
 if [ "$l_krp" = "$l_kpvalue" ]; then
 l_output="$l_output\n - \"$l_kpname\" is correctly set to \"$l_krp\" in the running configuration"
 else
 l_output2="$l_output2\n - \"$l_kpname\" is incorrectly set to \"$l_krp\" in the running configuration and should have a value of: \"$l_kpvalue\""
 fi
 if [ -n "$l_ufwscf" ]; then # Check UFW kernel parameter file first
 if grep -Pqs -- "^\h*$l_kpname\b" "$l_$l_ufwscf"; then
 l_var="$(grep -PHo -- "^\h*$l_kpname\h*=\h*\H+\b" "$l_$l_ufwscf" | tail -n 1)"
 fi
 fi
 if grep -Pqs -- "^\h*$l_kpname\b" /etc/sysctl.conf; then # Check /etc/sysctl.conf parameter file next
 l_var="$(grep -PHo -- "^\h*$l_kpname\h*=\h*\H+\b" /etc/sysctl.conf | tail -n 1)"
 fi
 if [ -z "$l_var" ]; then # If non found yet, now we loop find actual conf file parameter setting based on presence
 for l_keyname in "${a_sorted[@]}";do 
 if grep -Pqs -- "^\h*$l_kpname\b" "${A_files["$l_keyname"]}"; then
 l_var="$(grep -PHo -- "^\h*$l_kpname\h*=\h*\H+\b" "${A_files["$l_keyname"]}" | tail -n 1)"
 break
 fi
 done
 fi
 if [ -n "$l_var" ]; then
 while IFS=":" read -r l_conf_file l_var2; do
 while IFS="=" read -r l_fkpname l_fkpvalue; do
 l_fkpname="${l_fkpname// /}"; l_fkpvalue="${l_fkpvalue// /}"
 if [ "$l_fkpvalue" = "$l_kpvalue" ]; then
 l_output="$l_output\n - \"$l_kpname\" is correctly set to \"$l_fkpvalue\" in \"$l_conf_file\"\n"
 else
 l_output2="$l_output2\n - \"$l_kpname\" is incorrectly set to \"$l_fkpvalue\" in \"$l_conf_file\" and should have a value of: \"$l_kpvalue\"\n"
 fi
 done <<< "$l_var2"
 done <<< "$l_var"
 else
 l_output2="$l_output2\n - \"$l_kpname\" is not set in an included file\n ** Note: \"$l_kpname\" May be set in a file that's ignored by load procedure **\n"
 fi
 }
 while IFS="=" read -r l_kpname l_kpvalue; do # Assess and check parameters
 l_kpname="${l_kpname// /}"; l_kpvalue="${l_kpvalue// /}"
 if ! grep -Pqs '^\h*0\b' /sys/module/ipv6/parameters/disable && grep -q '^net.ipv6.' <<< "$l_kpname"; then
 l_output="$l_output\n - IPv6 is disabled on the system, \"$l_kpname\" is not applicable"
 else
 kernel_parameter_chk
 fi
 done < <(printf '%s\n' "${a_parlist[@]}")
 unset A_files; unset a_sorted # Remove arrays
 if [ -z "$l_output2" ]; then # Provide output from checks
 echo -e "\n- Audit Result:\n ** PASS **\n$l_output\n"
 else
 echo -e "\n- Audit Result:\n ** FAIL **\n - Reason(s) for audit failure:\n$l_output2\n"
 [ -n "$l_output" ] && echo -e "\n- Correctly set:\n$l_output\n"
 fi
}
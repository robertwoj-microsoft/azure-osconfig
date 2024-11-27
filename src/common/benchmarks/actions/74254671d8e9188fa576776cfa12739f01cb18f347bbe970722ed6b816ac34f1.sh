#!/usr/bin/env bash

{
 a_output2=()
 l_analyze_cmd="$(readlink -f /bin/systemd-analyze)" l_include='\$IncludeConfig' a_config_files=("/etc/rsyslog.conf")
 while IFS= read -r l_file; do
 l_conf_loc="$(awk '$1~/^\s*'"$l_include"'$/ {print $2}' "$(tr -d '# ' <<< "$l_file")" | tail -n 1)"
 [ -n "$l_conf_loc" ] && break
 done < <($l_analyze_cmd cat-config "${a_config_files[@]}" | tac | grep -Pio '^\h*#\h*\/[^#\n\r\h]+\.conf\b')
 if [ -d "$l_conf_loc" ]; then
 l_dir="$l_conf_loc" l_ext="*"
 elif grep -Psq '\/\*\.([^#/\n\r]+)?\h*$' <<< "$l_conf_loc" || [ -f "$(readlink -f "$l_conf_loc")" ]; then
 l_dir="$(dirname "$l_conf_loc")" l_ext="$(basename "$l_conf_loc")"
 fi
 while read -r -d $'\0' l_file_name; do
 [ -f "$(readlink -f "$l_file_name")" ] && a_config_files+=("$(readlink -f "$l_file_name")")
 done < <(find -L "$l_dir" -type f -name "$l_ext" -print0 2>/dev/null)
 for l_logfile in "${a_config_files[@]}"; do
 l_fail="$(grep -Psi -- '^\h*module\(load=\"?imtcp\"?\)' "$l_logfile")"
 [ -n "$l_fail" ] && a_output2+=("- Advanced format entry to accept incoming logs: \"$l_fail\"" "found in: \"$l_logfile\"")
 l_fail="$(grep -Psi -- '^\h*input\(type=\"?imtcp\"?\b' "$l_logfile")"
 [ -n "$l_fail" ] && a_output2+=("- Advanced format entry to accept incoming logs: \"$l_fail\"" "found in: \"$l_logfile\"")
 l_fail="$(grep -Psi -- '^\h*module\(load=\"?imtcp\"?\)' "$l_logfile")"
 [ -n "$l_fail" ] && a_output2+=("- Obsolete format entry to accept incoming logs: \"$l_fail\"" "found in: \"$l_logfile\"")
 l_fail="$(grep -Psi -- '^\h*input\(type=\"?imtcp\"?\b' "$l_logfile")"
 [ -n "$l_fail" ] && a_output2+=("- Obsolete format entry to accept incoming logs: \"$l_fail\"" "found in: \"$l_logfile\"")
 done
 if [ "${#a_output2[@]}" -le "0" ]; then
 printf '%s\n' "" "- Audit Result:" " ** PASS **" " - No entries to accept incoming logs found"
 else
 printf '%s\n' "" "- Audit Result:" " ** FAIL **" " - Reason(s) for audit failure:" "${a_output2[@]}"
 fi
}
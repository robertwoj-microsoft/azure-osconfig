#!/usr/bin/env bash

{
 l_analyze_cmd="$(readlink -f /bin/systemd-analyze)" l_include='\$IncludeConfig' a_config_files=("rsyslog.conf")
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
 grep -Hs -- "^*.*[^I][^I]*@" "$l_logfile"
 done
}
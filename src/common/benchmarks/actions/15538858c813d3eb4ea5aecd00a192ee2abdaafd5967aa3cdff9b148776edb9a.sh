#!/usr/bin/env bash

{
 l_analyze_cmd="$(readlink -f /bin/systemd-analyze)" l_config_file="/etc/logrotate.conf"
 l_include="$(awk '$1~/^\s*include$/{print$2}' "$l_config_file" 2>/dev/null)"
 [ -d "$l_include" ] && l_include="$l_include/*"
 $l_analyze_cmd cat-config "$l_config_file" $l_include
}
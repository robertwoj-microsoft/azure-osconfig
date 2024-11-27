#!/usr/bin/env bash

{
 a_kpar=("net.ipv6.conf.all.disable_ipv6=1" "net.ipv6.conf.default.disable_ipv6=1")
 l_searchloc="/run/sysctl.d/*.conf /etc/sysctl.d/*.conf /usr/local/lib/sysctl.d/*.conf /usr/lib/sysctl.d/*.conf /lib/sysctl.d/*.conf /etc/sysctl.conf $([ -f /etc/default/ufw ] && awk -F= '/^\s*IPT_SYSCTL=/ {print $2}' /etc/default/ufw)"
 for l_kpar in "${a_kpar[@]}"; do
 while IFS='=' read -r l_kpn l_kpv; do
 l_kpn="${l_kpn// /}"; l_kpv="${l_kpv// /}"
 while read -r l_file; do
 echo -e " - \"$l_kpn\" is set to \"$l_kpv\" in \"$l_file\"\n - Commenting out \"${l_kpn}=${l_kpv}\" in \"$l_file\""
 sed -ri 's/^\s*'"$l_kpn"'/# &/' "$l_file"
 done < <(grep -Psl -- '^\h*'"$l_kpn"'\h*=\h*'"$l_kpv"'\b' $l_searchloc)
 done <<< "$l_kpar"
 done
 unset a_kpar
}
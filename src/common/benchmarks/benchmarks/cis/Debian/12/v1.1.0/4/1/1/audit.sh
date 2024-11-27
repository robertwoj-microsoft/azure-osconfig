#!/usr/bin/env bash

{
 active_firewall=() firewalls=("ufw" "nftables" "iptables")
 # Determine which firewall is in use
 for firewall in "${firewalls[@]}"; do
 case $firewall in
 nftables)
 cmd="nft" ;;
 *)
 cmd=$firewall ;;
 esac 
 if command -v $cmd &> /dev/null && systemctl is-enabled --quiet $firewall && systemctl is-active --quiet $firewall; then
 active_firewall+=("$firewall")
 fi
 done
 # Display audit results
 if [ ${#active_firewall[@]} -eq 1 ]; then
 printf '%s\n' "" "Audit Results:" " ** PASS **" " - A single firewall is in use follow the recommendation in ${active_firewall[0]} subsection ONLY"
 elif [ ${#active_firewall[@]} -eq 0 ]; then
 printf '%s\n' "" " Audit Results:" " ** FAIL **" "- No firewall in use or unable to determine firewall status"
 else
 printf '%s\n' "" " Audit Results:" " ** FAIL **" " - Multiple firewalls are in use: ${active_firewall[*]}"
 fi 
}
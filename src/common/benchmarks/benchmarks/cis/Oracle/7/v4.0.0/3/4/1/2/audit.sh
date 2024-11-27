#!/usr/bin/env bash

{
 l_output=""
 if rpm -q firewalld &>/dev/null; then
 l_output="$l_output\n - FirewallD is installed"
 if systemctl is-enabled firewalld.service | grep -q '^enabled'; then
 l_output="$l_output\n - firewalld.service is enabled"
 else
 l_output="$l_output\n - firewalld.service is not enabled"
 fi
 if systemctl is-active firewalld.service | grep -q '^active'; then
 l_output="$l_output\n - firewalld.service is active"
 else
 l_output="$l_output\n - firewalld.service is not active"
 fi
 else
 l_output="$l_output\n - FirewallD is not installed"
 fi
 if rpm -q nftables &>/dev/null; then
 l_output="$l_output\n - nftables is installed"
 if systemctl is-enabled nftables.service | grep -q '^enabled'; then
 l_output="$l_output\n - nftables.service is enabled"
 else
 l_output="$l_output\n - nftables.service is not enabled"
 fi
 if systemctl is-active nftables.service | grep -q '^active'; then
 l_output="$l_output\n - nftables.service is active"
 else
 l_output="$l_output\n - nftables.service is not active"
 fi
 else
 l_output="$l_output\n - nftables is not installed"
 fi
 if rpm -q iptables-services &>/dev/null; then
 l_output="$l_output\n - iptables-services is installed"
 if systemctl is-enabled iptables.service | grep -q '^enabled'; then
 l_output="$l_output\n - iptables.service is enabled"
 else
 l_output="$l_output\n - iptables.service is not enabled"
 fi
 if systemctl is-active iptables.service | grep -q '^active'; then
 l_output="$l_output\n - iptables.service is active"
 else
 l_output="$l_output\n - iptables.service is not active"
 fi
 if grep -Pqs '^\h*0\b' /sys/module/ipv6/parameters/disable; then
 if systemctl is-enabled ip6tables.service | grep -q '^enabled'; then
 l_output="$l_output\n - ip6tables.service is enabled"
 else
 l_output="$l_output\n - ip6tables.service is not enabled"
 fi
 if systemctl is-active ip6tables.service | grep -q '^active'; then
 l_output="$l_output\n - ip6tables.service is active"
 else
 l_output="$l_output\n - ip6tables.service is not active"
 fi
 fi
 else
 l_output="$l_output\n - iptables-services is not installed"
 fi
 echo -e "$l_output"
}
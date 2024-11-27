# iptables -L INPUT -v -n
Chain INPUT (policy DROP 0 packets, 0 bytes)
 pkts bytes target prot opt in out source destination
 0 0 ACCEPT all -- lo * 0.0.0.0/0 0.0.0.0/0
 0 0 DROP all -- * * 127.0.0.0/8 0.0.0.0/0

 # iptables -L OUTPUT -v -n
Chain OUTPUT (policy DROP 0 packets, 0 bytes)
 pkts bytes target prot opt in out source destination
 0 0 ACCEPT all -- * lo 0.0.0.0/0 0.0.0.0/0
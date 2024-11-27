# ip6tables -L INPUT -v -n
Chain INPUT (policy DROP 0 packets, 0 bytes)
pkts bytes target prot opt in out source destination
 0 0 ACCEPT all lo * ::/0 ::/0 
 0 0 DROP all * * ::1 ::/0 

# ip6tables -L OUTPUT -v -n
Chain OUTPUT (policy DROP 0 packets, 0 bytes)
pkts bytes target prot opt in out source destination
 0 0 ACCEPT all * lo ::/0 ::/0
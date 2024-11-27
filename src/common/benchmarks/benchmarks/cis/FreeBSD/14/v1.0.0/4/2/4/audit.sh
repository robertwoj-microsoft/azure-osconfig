# sshd -T -C user=root -C host="$(hostname)" -C addr="$(grep $(hostname) /etc/hosts | awk '{print $1}')" | grep -Ei '^\s*(allow|deny)(users|groups)\s+\S+(\s+.*)?$'

# grep -Ei '^\s*(allow|deny)(users|groups)\s+\S+(\s+.*)?$' /etc/ssh/sshd_config
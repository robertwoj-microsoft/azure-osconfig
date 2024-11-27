# sshd -T -C user=root -C host="$(hostname)" -C addr="$(hostname -I | cut -d ' ' -f1)" | grep -Pi 'kexalgorithms\h+([^#\n\r]+,)?(diffie-hellman-group1-sha1|diffie-hellman-group14-sha1|diffie-hellman-group-exchange-sha1)\b'

Nothing should be returned
# sed -ri 's/^\s*minlen\s*=/# &/' /etc/security/pwquality.conf
# printf '\n%s' "minlen = 14" >> /etc/security/pwquality.conf.d/50-pwlength.conf
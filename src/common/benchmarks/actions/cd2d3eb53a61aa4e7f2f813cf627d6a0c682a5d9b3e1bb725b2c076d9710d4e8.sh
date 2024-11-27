# sed -ri 's/^\s*maxrepeat\s*=/# &/' /etc/security/pwquality.conf
# printf '\n%s' "maxrepeat = 3" >> /etc/security/pwquality.conf.d/50-pwrepeat.conf
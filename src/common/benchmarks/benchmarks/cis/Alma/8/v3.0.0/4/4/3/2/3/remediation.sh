# sed -ri 's/^\s*minclass\s*=/# &/' /etc/security/pwquality.conf
# printf '\n%s' "minclass = 4" >> /etc/security/pwquality.conf.d/50-pwcomplexity.conf
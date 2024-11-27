# grep -P '^\s*password\s+(requisite|required)\s+pam_cracklib.so\s+([^#]+\s+)*minlen=(1[4-9]|[1-9][0-9]+)\b' /etc/pam.d/common-password

password requisite pam_cracklib.so retry=3 minlen=14 dcredit=-1 ucredit=-1 lcredit=-1 ocredit=-1
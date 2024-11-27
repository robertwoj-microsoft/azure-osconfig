# grep "pam_tally2" /etc/pam.d/common-auth

auth required pam_tally2.so onerr=fail audit silent deny=5 unlock_time=900
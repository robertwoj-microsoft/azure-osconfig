# grep -Ei '^auth\s+(required|requisite)+\s+pam_group\.so\s+\S+\s(group=\S+\b)' /etc/pam.d/su

auth requisite pam_group.so no_warn group=wheel root_only fail_safe ruser
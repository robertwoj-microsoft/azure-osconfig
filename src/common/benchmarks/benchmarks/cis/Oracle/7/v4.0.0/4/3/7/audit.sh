# grep -Pi '^\h*auth\h+[^#\n\r]+\h+pam_wheel\.so\h+([^#\n\r]+\h+)?(use_uid|group=\H+)\h+([^#\n\r]+\h+)?(use_uid|group=\H+)\b' /etc/pam.d/su

auth required pam_wheel.so use_uid group=<group_name>
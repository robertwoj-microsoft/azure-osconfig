# grep -P -- '^\h*password\h+([^#\n\r]+\h+)?(pam_pwhistory\.so|pam_unix\.so)\b' /etc/pam.d/common-password

password required pam_pwhistory.so remember=5
password [success=1 default=ignore] pam_unix.so obscure sha512 use_authtok
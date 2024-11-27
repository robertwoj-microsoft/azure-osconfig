# grep -Pi -- '^\h*password\h+(required|requisite)\h+pam_pwhistory\.so\h+([^#\n\r]+\h+)?remember=(2[4-9]|[3-9][0-9]|[1-9][0-9]{2,})\b' /etc/pam.d/{system,password}-auth

remember = 24
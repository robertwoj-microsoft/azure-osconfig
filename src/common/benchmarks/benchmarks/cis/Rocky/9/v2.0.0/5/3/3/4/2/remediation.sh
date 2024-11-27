#!/usr/bin/env bash

{
 l_pam_profile="$(head -1 /etc/authselect/authselect.conf)"
 if grep -Pq -- '^custom\/' <<< "$l_pam_profile"; then
 l_pam_profile_path="/etc/authselect/$l_pam_profile"
 else
 l_pam_profile_path="/usr/share/authselect/default/$l_pam_profile"
 fi
 grep -P -- '^\h*password\h+([^#\n\r]+\h+)pam_unix\.so\b' "$l_pam_profile_path"/{password,system}-auth
}
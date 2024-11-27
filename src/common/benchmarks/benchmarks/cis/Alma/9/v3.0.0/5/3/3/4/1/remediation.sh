{
 l_module_name="unix"
 l_profile_name="$(head -1 /etc/authselect/authselect.conf)"
 if [[ ! "$l_profile_name" =~ ^custom\/ ]]; then
 echo " - Follow Recommendation \"Ensure custom authselect profile is used\" and then return to this Recommendation"
 else
 grep -P -- "\bpam_$l_module_name\.so\b" /etc/authselect/$l_profile_name/{password,system}-auth
 fi
}
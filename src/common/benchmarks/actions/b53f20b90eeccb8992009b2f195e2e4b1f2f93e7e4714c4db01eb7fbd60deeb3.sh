#!/urs/bin/env bash

{
 [ ! -d /etc/security/pwquality.conf.d/ ] && mkdir /etc/security/pwquality.conf.d/
 printf '\n%s\n' "enforce_for_root" > /etc/security/pwquality.conf.d/50-pwroot.conf
}
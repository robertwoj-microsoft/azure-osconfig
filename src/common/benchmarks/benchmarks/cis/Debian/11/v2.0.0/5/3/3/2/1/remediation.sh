#!/usr/bin/env bash

{
 sed -ri 's/^\s*difok\s*=/# &/' /etc/security/pwquality.conf
 [ ! -d /etc/security/pwquality.conf.d/ ] && mkdir /etc/security/pwquality.conf.d/
 printf '\n%s' "difok = 2" > /etc/security/pwquality.conf.d/50-pwdifok.conf
}
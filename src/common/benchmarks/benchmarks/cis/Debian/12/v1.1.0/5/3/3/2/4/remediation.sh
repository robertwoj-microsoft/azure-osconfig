#!/usr/bin/env bash

{
 sed -ri 's/^\s*maxrepeat\s*=/# &/' /etc/security/pwquality.conf
 [ ! -d /etc/security/pwquality.conf.d/ ] && mkdir /etc/security/pwquality.conf.d/
 printf '\n%s' "maxrepeat = 3" > /etc/security/pwquality.conf.d/50-pwrepeat.conf
}
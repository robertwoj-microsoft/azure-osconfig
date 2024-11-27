#!/usr/bin/env bash

{
 sed -ri 's/^\s*minlen\s*=/# &/' /etc/security/pwquality.conf
 [ ! -d /etc/security/pwquality.conf.d/ ] && mkdir /etc/security/pwquality.conf.d/
 printf '\n%s' "minlen = 14" > /etc/security/pwquality.conf.d/50-pwlength.conf
}
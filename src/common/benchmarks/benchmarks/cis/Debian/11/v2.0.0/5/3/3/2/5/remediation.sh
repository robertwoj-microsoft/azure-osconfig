#!/usr/bin/env bash

{
 sed -ri 's/^\s*maxsequence\s*=/# &/' /etc/security/pwquality.conf
 [ ! -d /etc/security/pwquality.conf.d/ ] && mkdir /etc/security/pwquality.conf.d/
 printf '\n%s' "maxsequence = 3" > /etc/security/pwquality.conf.d/50-pwmaxsequence.conf
}
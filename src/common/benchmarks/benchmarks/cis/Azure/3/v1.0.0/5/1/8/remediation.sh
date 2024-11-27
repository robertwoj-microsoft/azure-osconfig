#!/usr/bin/env bash

{
 if rpm -q cronie >/dev/null; then
 [ -e /etc/cron.deny ] && rm -f /etc/cron.deny
 [ ! -e /etc/cron.allow ] && touch /etc/cron.allow
 chown root:root /etc/cron.allow
 chmod g-wx,o-rwx /etc/cron.allow
 else
 echo "cron is not installed on the system"
 fi
}
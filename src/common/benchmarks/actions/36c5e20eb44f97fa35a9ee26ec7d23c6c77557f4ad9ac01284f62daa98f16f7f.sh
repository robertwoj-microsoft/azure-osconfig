#!/usr/bin/env bash

{
 [ ! -e "/etc/cron.deny" ] && touch /etc/cron.allow
 chmod u-x,g-wx,o-rwx /etc/cron.allow
 if grep -Pq -- '^\h*crontab\:' /etc/group; then
 chown root:crontab /etc/cron.allow
 else
 chown root:root /etc/cron.allow
 fi
}
#!/bin/sh

{
 [ ! -e "/var/at/at.allow" ] && touch /var/at/at.allow
 chown root:wheel /var/at/at.allow
 chmod u-x,g-wx,o-rwx /var/at/at.allow
 [ -e "/var/at/at.deny" ] && chown root:wheel /var/at/at.deny
 [ -e "/var/at/at.deny" ] && chmod u-x,g-wx,o-rwx /var/at/at.deny
}
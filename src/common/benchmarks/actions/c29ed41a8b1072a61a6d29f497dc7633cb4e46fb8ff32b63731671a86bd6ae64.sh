#!/usr/bin/env bash

{
 a_parameters=('*.* action(type="omfwd" target="loghost.example.com" port="514" protocol="tcp"' \
 ' action.resumeRetryCount="100"' ' queue.type="LinkedList" queue.size="1000")')
 [ ! -d "/etc/rsyslog.d/" ] && mkdir /etc/rsyslod.d/
 printf '%s\n' "" "${a_parameters[@]}" >> /etc/rsyslog.d/60-rsyslog.conf
}
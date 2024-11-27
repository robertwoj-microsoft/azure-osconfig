# grep /sbin/sulogin /usr/lib/systemd/system/rescue.service

ExecStart=-/bin/sh -c "/sbin/sulogin; /usr/bin/systemctl --fail --no-block default"
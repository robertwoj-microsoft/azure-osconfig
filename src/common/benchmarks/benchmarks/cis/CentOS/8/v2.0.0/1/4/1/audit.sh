#!/usr/bin/env bash

{
 tst1="" tst2="" output=""
 grubdir=$(dirname "$(find /boot -type f \( -name 'grubenv' -o -name 'grub.conf' -o -name 'grub.cfg' \) -exec grep -El '^\s*(kernelopts=|linux|kernel)' {} \;)")
 if [ -f "$grubdir/user.cfg" ]; then
 grep -Pq '^\h*GRUB2_PASSWORD\h*=\h*.+$' "$grubdir/user.cfg" && output="bootloader password set in \"$grubdir/user.cfg\""
 fi
 if [ -z "$output" ]; then
 grep -Piq '^\h*set\h+superusers\h*=\h*"?[^"\n\r]+"?(\h+.*)?$' "$grubdir/grub.cfg" && tst1=pass
 grep -Piq '^\h*password(_pbkdf2)?\h+\H+\h+.+$' "$grubdir/grub.cfg" && tst2=pass
 [ "$tst1" = pass ] && [ "$tst2" = pass ] && output="bootloader password set in \"$grubdir/grub.cfg\""
 fi
 [ -n "$output" ] && echo -e "\n\n PASSED! $output\n\n"
}
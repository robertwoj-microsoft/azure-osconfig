#!/usr/bin/env bash

{
 output="" output2="" output3="" output4=""
 grubdir=$(dirname "$(find /boot -type f \( -name 'grubenv' -o -name 'grub.conf' -o -name 'grub.cfg' \) -exec grep -Pl '^\h*(kernelopts=|linux|kernel)' {} \;)")
 for grubfile in $grubdir/user.cfg $grubdir/grubenv $grubdir/grub.cfg; do
 if [ -f "$grubfile" ]; then
 if stat -c "%a" "$grubfile" | grep -Pq '^\h*[0-7]00$'; then
 output="$output\npermissions on \"$grubfile\" are \"$(stat -c "%a" "$grubfile")\""
 else
 output3="$output3\npermissions on \"$grubfile\" are \"$(stat -c "%a" "$grubfile")\""
 fi
 if stat -c "%u:%g" "$grubfile" | grep -Pq '^\h*0:0$'; then
 output2="$output2\n\"$grubfile\" is owned by \"$(stat -c "%U" "$grubfile")\" and belongs to group \"$(stat -c "%G" "$grubfile")\""
 else
 output4="$output4\n\"$grubfile\" is owned by \"$(stat -c "%U" "$grubfile")\" and belongs to group \"$(stat -c "%G" "$grubfile")\""
 fi
 fi
 done
 if [[ -n "$output" && -n "$output2" && -z "$output3" && -z "$output4" ]]; then
 echo -e "\nPASSED:"
 [ -n "$output" ] && echo -e "$output"
 [ -n "$output2" ] && echo -e "$output2"
 else
 echo -e "\nFAILED:"
 [ -n "$output3" ] && echo -e "$output3"
 [ -n "$output4" ] && echo -e "$output4"
 fi
}
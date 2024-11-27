# grep ^shadow:[^:]*:[^:]*:[^:]+ /etc/group
# awk -F: -v GID="$(awk -F: '($1=="shadow") {print $3}' /etc/group)" '($4==GID) {print}' /etc/passwd
# for f in /etc/profile.d/*.sh ; do grep -Eq '(^|^[^#]*;)\s*(readonly|export(\s+[^$#;]+\s*)*)?\s*TMOUT=(900|[1-8][0-9][0-9]|[1-9][0-9]|[1-9])\b' $f &)\s*readonly\s+TMOUT\b' $f &)\s*export\s+([^$#;]+\s+)*TMOUT\b' $f & done

TMOUT correctly configured in file: <name of file where TMOUT is configured>
FROM ubuntu:jammy

RUN apt-get update
RUN apt-get install -y systemd
RUN apt-get install -y systemd-sysv
RUN apt-get install -y sudo
RUN apt-get install -y wget
RUN apt-get install -y lsof
RUN apt-get install -y curl
RUN apt-get install -y gnupg2
RUN apt-get install -y strace
RUN wget https://packages.microsoft.com/config/ubuntu/22.04/prod.list -O /etc/apt/sources.list.d/microsoft-prod.list
RUN wget -qO - https://packages.microsoft.com/keys/microsoft.asc | apt-key add -
RUN apt-get update
RUN apt-get update
RUN apt-get install -y vim

# Some stuff is required for audits to be clean
RUN apt-get install -y ssh
RUN apt-get install -y kmod

RUN apt-get update \
    && apt-get -y install --no-install-recommends powershell  \
    && wget https://github.com/microsoft/omi/releases/download/v1.9.1-0/omi-1.9.1-0.ssl_300.ulinux.s.x64.deb \
    && dpkg -i ./omi-1.9.1-0.ssl_300.ulinux.s.x64.deb \
    && rm -f ./omi-1.9.1-0.ssl_300.ulinux.s.x64.deb \
    && pwsh --command "Set-PSRepository -Name 'PSGallery' -InstallationPolicy Trusted" \
    && pwsh --command "Install-Module -Name GuestConfiguration" \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /app
COPY app/startup.bash /app/
COPY app/env.bash /app/
COPY app/arc-playground.service /lib/systemd/system/
COPY app/test_package.sh /app/
COPY app/run_gc_worker.sh /app/

RUN systemctl enable arc-playground.service

CMD [ "/sbin/init" ]

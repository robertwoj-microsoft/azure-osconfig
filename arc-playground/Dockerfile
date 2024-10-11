FROM ubuntu:jammy

RUN apt-get update
RUN apt-get install -y systemd
RUN apt-get install -y systemd-sysv
RUN apt-get install -y sudo
RUN apt-get install -y wget
RUN apt-get install -y lsof
RUN apt-get install -y curl
RUN apt-get install -y gnupg2
RUN wget https://packages.microsoft.com/config/ubuntu/22.04/prod.list -O /etc/apt/sources.list.d/microsoft-prod.list
RUN wget -qO - https://packages.microsoft.com/keys/microsoft.asc | apt-key add -
RUN apt-get update

# Some stuff is required for audits to be clean
RUN apt-get install -y ssh
RUN apt-get install -y kmod

RUN mkdir /app
COPY app/startup.bash /app/
COPY app/env.bash /app/
COPY app/arc-playground.service /lib/systemd/system/

RUN systemctl enable arc-playground.service

CMD [ "/sbin/init" ]

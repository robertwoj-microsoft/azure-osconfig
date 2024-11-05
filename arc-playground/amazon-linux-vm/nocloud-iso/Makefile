# enviroment variables set defautl to those values unless from cmdline, env
SSH_PUB_KEY?=$(shell cat ~/.ssh/id_rsa.pub)
VM_HOSTNAME?=awslinux20_vm0


# default target
all: seed.iso

SYSTEM:=$(shell uname -s)
# SYSTEM:=Linux

seedconfig/user-data seedconfig/meta-data: % : %.tmplt
	( SSH_PUB_KEY="${SSH_PUB_KEY}" VM_HOSTNAME=${VM_HOSTNAME} envsubst < $^ > $@ )

seed.iso: seedconfig/user-data seedconfig/meta-data
	-rm seed.iso
ifeq (${SYSTEM}, Darwin)
		hdiutil makehybrid -o seed.iso -hfs -joliet -iso -default-volume-name cidata seedconfig/ 
endif 
ifeq (${SYSTEM}, Linux)
		mkisofs -output seed.iso -volid cidata -joliet -rock seedconfig/user-data seedconfig/meta-data 
endif 

clean:
	-rm seed.iso seedconfig/user-data seedconfig/meta-data

help:
	@echo 'make will build seed.iso for Amazon Linux 2 as cloduinit'
	@echo  'The seed.iso will create user:'
	@echo  '   ec2-user'
	@echo  '	  with password amazon '
	@echo  '	  authorized_keys equal to SSH_PUB_KEY, default ~./.ssh/id_rsa.pub'
	@echo  '   hostname equal VM_HOSTNAME, default awslinux20_vm0'

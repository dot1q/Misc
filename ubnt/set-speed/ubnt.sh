#!/bin/sh
#poorly written by dot1q

#Specify passwords and stuff here
USERNAME="jdoe"
PASSWORD="hippos"
FILELOCATION = http://images.sandynet.org/script/setspeed_m

echo "This script is very simple and does not do a lot of error checking. Use at your own risk!"

#Read through every line of ip.txt and then ssh into it
while read line
do

	#apt-get install sshpass
	sshpass -p "$PASSWORD" ssh -o StrictHostKeyChecking=no $USERNAME@$line '
		cd /tmp
		wget $FILELOCATION
		chmod 777 setspeed_m
		./setspeed_m
	'
	echo "$line has been executed!"
done <ip.txt


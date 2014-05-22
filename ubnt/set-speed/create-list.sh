#!/bin/bash
#poorly written by dot1q

#delete previous entries
rm ip.txt

#prompt user for input
echo "This script only works with a class C address space"
echo "Please the IP prefix [xxx.xxx.xxx.]: "
read PREFIX
echo "Please enter the start address[1-254]: "
read START
echo "Please enter the end address[1-254]: "
read END

#write all entries to ip.txt
for ((i=$START; $i<=$END; i++))
do
 echo $PREFIX$i>>ip.txt
done

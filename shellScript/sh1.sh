#!/bin/bash
#program:
#    this is kqy 
#echo -e "helo, kqy first shell \a \n"
#read -p "input your name:" firstname

#echo -e "\n this is: $firstname"
echo 'date'
read -p "input userer:" fileuser
filename=${fileuser:-"filename"}

#date1=$ (date --date='2 days ago' + %Y%m%d)
date3=$(date +%Y%m%d)
#file1=$(filename)${date3}
#touch "$file1"
touch "$date3"
exit 0

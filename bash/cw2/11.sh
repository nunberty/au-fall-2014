#!/bin/bash
# Alina Kramar

ips=$(ifconfig|grep -Po "inet addr:\d{1,3}\.\d{1,3}\.\d{1,3}"|grep -Po "\d.*")

for ip in $ips
do
    if [[ $ip != 127.0.0 ]]
    then
        for host in $(seq 1 254)
        do
            ping -c 1 $ip$host > /dev/null
            if [[ $? == 0 ]]
            then
                echo $ip$host
            fi
        done
    fi
done

#!/bin/bash
# Alina Kramar

ips=$(ip addr | grep -Po "inet \d{1,3}\.\d{1,3}\.\d{1,3}" | grep -Po "\d.*")

for ip in $ips
do
    if [[ $ip != 127.0.0 ]]
    then
        for host in $(seq 1 254)
        do
            ping -c 1 $ip.$host > /dev/null
            [ $? -eq 0 ] && echo $ip.$host
        done
    fi
done

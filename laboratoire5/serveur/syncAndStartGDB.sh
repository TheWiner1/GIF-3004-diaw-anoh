#!/bin/bash
set -e

# Sync executable
bn=$(basename $1)
rsync -az $1/build/SETR_LABO5_SERVEUR pi@$2:/home/pi/projects/laboratoire5/SETR_LABO5_SERVEUR

# Execute GDB
ssh pi@$2 "nohup gdbserver :4567 /home/pi/projects/laboratoire5/SETR_LABO5_SERVEUR > /dev/null 2> /dev/null < /dev/null &"
sleep 1 

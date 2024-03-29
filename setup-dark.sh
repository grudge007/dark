#!/bin/sh
sudo apt install gcc
gcc -o dark dark.c
sudo cp dark /usr/games/.
python3 anim.py




./anim.sh

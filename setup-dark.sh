#!/bin/sh
sudo apt install gcc -y
cd dark
cp .dark.txt ~/.
gcc -o dark dark.c 
sudo cp dark /usr/games/.
python3 anim.py



chmod +x anim.sh
./anim.sh

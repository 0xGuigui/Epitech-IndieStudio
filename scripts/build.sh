##
## EPITECH PROJECT, 2022
## B-YEP-400-LIL-4-1-indiestudio-paul.gervais
## File description:
## build
##

#!/bin/bash

if [ $1 == "--run" ] || [ $1 == "-r" ]; then
  cmake . && make && ./bomberman
else
  cmake . && make
fi

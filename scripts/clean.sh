##
## EPITECH PROJECT, 2022
## B-YEP-400-LIL-4-1-indiestudio-paul.gervais
## File description:
## clean
##

#!/bin/bash

targetToDelete=(
  "bomberman"
  "bomberman.cpb"
  "bomberman.exe"
  "CMakeCache.txt"
  "Testing"
  "CMakeFiles"
  "cmake_install.cmake"
  "Makefile"
  "_deps"
  ".cmake")

for i in "${targetToDelete[@]}"
do
  rm -rf $i
done

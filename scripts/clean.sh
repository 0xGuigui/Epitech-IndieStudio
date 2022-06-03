#!/bin/bash
##
## EPITECH PROJECT, 2022
## B-YEP-400-LIL-4-1-indiestudio-paul.gervais
## File description:
## clean
##

targetToDelete=(
  "bomberman"
  "bomberman.cpb"
  "bomberman.exe"
  "CMakeCache.txt"
  "Testing"
  "CMakeFiles"
  "cmake_install.cmake"
  "CPackConfig.cmake"
  "CPackSourceConfig.cmake"
  "Makefile"
  "_deps"
  ".cmake")

for i in "${targetToDelete[@]}"
do
  rm -rf $i
done

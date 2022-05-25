#!/bin/bash

if [ $1 == "--run" ] || [ $1 == "-r" ]; then
  cmake . && make && ./bomberman
else
  cmake . && make
fi

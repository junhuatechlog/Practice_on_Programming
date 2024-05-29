#!/bin/sh
g++44 -o test Source.cpp
if [ $? -ne 0 ];
then
    echo "compilation failed!"
    exit 1
else
    echo "compilation successfully!"
fi
./test <in\ .txt > output.txt


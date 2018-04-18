#!/bin/sh

#GPP=g++
GPP=clang

$GPP -Wall -Wstrict-overflow=5 -std=c++11 -Os -I../xenum/lib/inc ${1}.cpp -o ${1}


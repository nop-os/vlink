# Standard Unix

TARGET = vlink
DIR = objects

CC = gcc
CCOUT = -o $(DUMMYVARIABLE)	# produces the string "-o "
COPTS = -std=c9x -Ofast -fomit-frame-pointer -c -DLIBPATH="\"$(shell dirname $(shell pwd))/cross/lib\""
CONFIG =

LD = gcc
LDOUT = -o $(DUMMYVARIABLE)	# produces the string "-o "
LDOPTS =
LIBS =

include make.rules

# Standard Unix with gcc

TARGET = vlink
DIR = objects
MD = mkdir
RM = rm -f

CC = gcc
CCOUT = -o $(DUMMYVARIABLE)	# produces the string "-o "
COPTS = -std=c99 -pedantic -Ofast -fomit-frame-pointer -c -DLIBPATH="\"$(shell dirname $(shell pwd))/cross/lib\""
CONFIG =

LD = $(CC)
LDOUT = -o $(DUMMYVARIABLE)	# produces the string "-o "
LDOPTS =
LIBS =


include make.rules

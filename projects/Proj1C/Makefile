# - Makefile - #
# Luke Donnelly
# CIS_330 #

CC=gcc
CFLAGS=-g
INSTALL_DIR=~/CIS_330/projects/Proj1C


AR=ar
AR_FLAGS=r

SOURCES=$(wildcard trig/*.c) $(wildcard exp/*.c)
OBJECTS=$(SOURCES:.c=.o)

cli: include lib $(OBJECTS)
	$(CC) $(CFLAGS) -o math330 cli/cli.c -Iinclude -Llib -lProj1C -lm

lib: $(OBJECTS)
	mkdir -p $(INSTALL_DIR)/lib
	mkdir -p $(INSTALL_DIR)/objs
	$(AR) $(AR_FLAGS) libProj1C.a *.o
	mv libProj1C.a $(INSTALL_DIR)/lib
	cp math330.h $(INSTALL_DIR)/include
	mv *.o $(INSTALL_DIR)/objs

include: math330.h
	mkdir -p $(INSTALL_DIR)/include
	cp math330.h $(INSTALL_DIR)/include

%.o : %.c
	$(CC) $(CFLAGS) -c $< -Iinclude

clean:
	rm -r include
	rm -r lib
	rm -r objs

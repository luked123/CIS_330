# Luke Donnelly
# CIS 330
# Makefile for Proj2B

CC=gcc
CFLAGS=-g
EXECUTABLE=proj2B

SOURCES=proj2B.c
OBJECTS=$(SOURCES:.c=.o)

proj2B: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) 

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(EXECUTABLE)

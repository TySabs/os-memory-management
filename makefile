##
# PROGRAM:    Assignment 6
# PROGRAMMER: Tyler Saballus
# LOGON ID:   z1836409
# DATE DUE:   11-14-2018
#

# Compiler variables
CC = g++
CCFLAGS = -Wall -pthread

# Rule to link object code files to create executable file
Assign6: hw6.o memoryblock.o
	$(CC) $(CCFLAGS) -o Assign6 hw6.o memoryblock.cc

# Rules to compile source code file to object code
hw6.o: hw6.cc
	$(CC) $(CCFLAGS) -c hw6.cc

memoryblock.o: memoryblock.cc memoryblock.h
	$(CC) $(CCFLAGS) -c memoryblock.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign6

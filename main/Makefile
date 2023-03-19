# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
bach: main.o functionen.o 
	$(CC) $(CFLAGS) -o bach main.o functionen.o 
 
# The main.o target can be written more simply
 
main.o: main.cpp bachelor.hpp 
	$(CC) $(CFLAGS) -c main.cpp
 
functionen.o: bachelor.hpp

clean: 
	rm -f *.o function main

checkstyle:
	clang-tidy --quiet $(wildcard *.cpp) $(wildcard *.hpp) --

format:
	clang-format -i $(wildcard *.cpp) $(wildcard *.hpp)
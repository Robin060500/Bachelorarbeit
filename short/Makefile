# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
bach_short: main_short.o functionen_short.o 
	$(CC) $(CFLAGS) -o bach_short main_short.o functionen_short.o 
 
# The main.o target can be written more simply
 
main_short.o: main_short.cpp bachelor_short.h 
	$(CC) $(CFLAGS) -c main_short.cpp
 
functionen_short.o: bachelor_short.h

clean: 
	rm -f *.o function_short main_short

checkstyle:
	clang-tidy --quiet $(wildcard *.cpp) $(wildcard *.hpp) --

format:
	clang-format -i $(wildcard *.cpp) $(wildcard *.hpp)

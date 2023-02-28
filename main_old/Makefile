# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
bach: main_old.o functionen_old.o 
	$(CC) $(CFLAGS) -o bach main_old.o functionen_old.o 
 
# The main.o target can be written more simply
 
main_old.o: main_old.cpp bachelor_old.hpp 
	$(CC) $(CFLAGS) -c main_old.cpp
 
functionen_old.o: bachelor_old.hpp

clean: 
	rm -f *.o function_old main_old

checkstyle:
	clang-tidy --quiet $(wildcard *.cpp) $(wildcard *.hpp) --

format:
	clang-format -i $(wildcard *.cpp) $(wildcard *.hpp)
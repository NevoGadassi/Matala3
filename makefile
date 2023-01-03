CC = gcc
CFLAGS = -g -Wall

all: isort txtfind

isort:
	$(CC) $(CFLAGS) -o isort insertionsort.c
txtfind:
	$(CC) $(CFLAGS) -o txtfind stringfunc.c
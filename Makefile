#
# Makefile
# 

CC = gcc

CFLAGS = -std=c99 -Wall -Werror -O3 
LIBS =

all: logtoyaml

#c
logtoyaml: main.c
	$(CC) $(CFLAGS) -o logtoyaml main.c

clean:
	rm -f -v logtoyaml

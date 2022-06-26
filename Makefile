CC=gcc
SRC=src
LIBS=lib
INCLUDE=include
OBJ=obj
CFLAGS=-Wall -g -O0 -I./$(INCLUDE)

EXTERNALLIBS=-lopengl32 -lgdi32

LOCALLIBS=$(wildcard $(LIBS)/**/*.o) $(wildcard $(LIBS)/**/*.a)
FILES=$(wildcard $(SRC)/*.c) $(wildcard $(SRC)/**/*.c)

all: build

build:
	$(CC) $(FILES) $(LOCALLIBS) $(EXTERNALLIBS) $(CFLAGS)

clean: a.exe
	del a.exe

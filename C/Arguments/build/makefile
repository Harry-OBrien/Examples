CC=gcc
CSRCFLAGS=-O2 -Wall -Wextra -std=c++17

SRC_DIR=..
OUT_NAME=$(shell basename `pwd`/..)

build:
	$(CC) $(SRC_DIR)/main.c -o $(OUT_NAME)

run: build
	./$(OUT_NAME) 

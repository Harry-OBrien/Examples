CC=gcc

SRCS=$(shell find .. -name *.cpp)
OBJS=$(patsubst %.c,%,$(SRCS))
OUT_NAMES=$(foreach file, $(SRC_FILES), $(shell basename $(shell dirname $(file))))

OUT_NAMES: $(OBJS)

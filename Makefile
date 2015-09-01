OBJS = src/main.cpp

CC = g++

OBJ_NAME = re

all: $(OBJS)
	$(CC) $(OBJS) `sdl2-config --cflags --libs` -o $(OBJ_NAME)


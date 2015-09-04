OBJS = src/main.cpp

CC = g++

OBJ_NAME = re

SDL=`sdl2-config --cflags --libs`

all: $(OBJS)
	$(CC) $(OBJS) $(SDL) -o $(OBJ_NAME)


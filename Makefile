CXX = g++
CFLAGS=-Wall
INCLUDE=`sdl2-config --cflags`
LIBS=`sdl2-config --libs`
SOURCES=src/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OUT=bin/re

all: $(OUT)

$(OUT): $(OBJECTS)
		$(CXX) $(CFLAGS) -o $(OUT) $(OBJECTS) $(LIBS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -rf $(OUT) $(OBJECTS)


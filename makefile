TARGET = lab2
CFLAGS = -Wall
SOURCES := $(wildcard *.cpp)
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

build: $(SOURCES)
	g++ $^ $(CFLAGS) -o $(TARGET) $(LIBS)

test: build
	./$(TARGET)

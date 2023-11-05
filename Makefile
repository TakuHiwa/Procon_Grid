CC=g++
CFLAGS=-lglut -lGLU -lGL
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

wn:	window
	./build/window.out

window: main.o
	mkdir -p build
	$(CC) -o ./build/window.out main.o $(CFLAGS)

sq: square
	./square.out

square: square.o
	mkdir -p build
	g++ square.o -o ./build/square.out -lglut -lGLU -lGL

clean:
		rm -rf ./build *.o 

.PHONY: test clean
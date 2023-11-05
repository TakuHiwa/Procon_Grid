CC=g++
CFLAGS=-lglut -lGLU -lGL
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

tt:	window
	./window

window: $(OBJS)
	$(CC) -o window $(OBJS) $(CFLAGS)

clean:
		rm -f window *.o 

.PHONY: test clean
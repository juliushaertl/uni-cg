CC = g++
CFLAGS = -Wall
DEPS = 
LDFLAGS = -lGL -lGLU -lglut -lGLEW
BUILDDIR = build/

all: demo1

demo1:
	$(CC) $@.cpp -o $(BUILDDIR)$@ $(LDFLAGS)

clean:
	rm $(BUILDDIR)demo1

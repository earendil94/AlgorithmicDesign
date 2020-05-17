CFLAGS=-I include

all: main.x

%.o: %.c
	gcc -c $< -o $@  $(CFLAGS)

src/Graph.o: include/Graph.h

main.o: src/Graph.o

main.x: main.o src/Graph.o
	gcc $^ -o $@

clean:
	rm -rf *.o src/*.o *.x


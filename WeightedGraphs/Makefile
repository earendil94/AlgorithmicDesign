CFLAGS=-I include
DIRHEAP=../AD_bin_heaps/lib
BINHEAP=-l binheap -l common -L $(DIRHEAP)

all: main.x

%.o: %.c
	gcc -c $< -o $@  $(CFLAGS) $(BINHEAP)

src/Graph.o: include/Graph.h
src/Node.o: include/Node.h
src/Queue.o: include/Queue.h

main.o: src/Graph.o src/Node.o src/Queue.o

main.x: main.o src/Graph.o src/Node.o src/Queue.o
	gcc $^ -o $@ $(BINHEAP) 

clean:
	rm -rf *.o src/*.o *.x


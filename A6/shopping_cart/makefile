CC := g++ --std=c++11
CC_OBJECT := $(CC) -c 

all: main

main: main.o item.o object.o box.o cartmanager.o
	$(CC) *.o -o main

main.o: main.cc
	$(CC_OBJECT) main.cc -o main.o

cartmanager.o: CartManager.hh CartManager.cc item.hh box.hh
	$(CC_OBJECT) CartManager.cc -o cartmanager.o

item.o: item.cc item.hh object.hh
	$(CC_OBJECT) item.cc -o item.o

box.o: box.cc box.hh object.hh
	$(CC_OBJECT) box.cc -o box.o

object.o: object.cc object.hh
	$(CC_OBJECT) object.cc -o object.o
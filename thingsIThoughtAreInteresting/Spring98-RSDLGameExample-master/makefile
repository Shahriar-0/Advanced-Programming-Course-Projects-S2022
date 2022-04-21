CC = g++
FLAGS = -std=c++11 -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
COMPILE_FLAGS = $(FLAGS) -c 

example.out: main.o Game.o Circle.o
	$(CC) main.o Game.o Circle.o rsdl.cpp $(FLAGS) -o example.out

main.o: main.cpp 
	$(CC) $(COMPILE_FLAGS) main.cpp

Circle.o: Circle.h Circle.cpp Game.h
	$(CC) $(COMPILE_FLAGS) Circle.cpp

Game.o: Game.h Game.cpp Circle.h
	$(CC) $(COMPILE_FLAGS) Game.cpp

Game.h: Circle.h

.PHONY: clean

clean:
	rm *.o
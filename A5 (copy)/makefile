CC := g++ -std=c++11
SDLFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

all: starwars.out

starwars.out: $(BUILDS)main.o $(BUILDS)audio.o $(BUILDS)rsdl.o $(BUILDS)bullet.o $(BUILDS)star_wars.o $(BUILDS)space_ship.o $(BUILDS)my_space_ship.o
	$(CC) $(BUILDS)*.o $(SDLFLAGS) -o starwars.out

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)star_wars.hpp
	$(CC_OBJECT) $(CODES)main.cpp -o $(BUILDS)main.o

$(BUILDS)star_wars.o: $(CODES)star_wars.cpp $(CODES)star_wars.hpp $(CODES)bullet.hpp $(CODES)my_space_ship.hpp $(CODES)audio.hpp
	$(CC_OBJECT) $(CODES)star_wars.cpp -o $(BUILDS)star_wars.o

$(BUILDS)space_ship.o: $(CODES)space_ship.cpp $(CODES)space_ship.hpp 
	$(CC_OBJECT) $(CODES)space_ship.cpp -o $(BUILDS)space_ship.o

$(BUILDS)my_space_ship.o: $(CODES)my_space_ship.cpp $(CODES)my_space_ship.hpp $(CODES)space_ship.hpp $(CODES)bullet.hpp
	$(CC_OBJECT) $(CODES)my_space_ship.cpp -o $(BUILDS)my_space_ship.o

$(BUILDS)bullet.o: $(CODES)bullet.cpp $(CODES)bullet.hpp 
	$(CC_OBJECT) $(CODES)bullet.cpp -o $(BUILDS)bullet.o

$(BUILDS)audio.o: $(CODES)audio.cpp $(CODES)audio.hpp 
	$(CC_OBJECT) $(CODES)audio.cpp -o $(BUILDS)audio.o

$(BUILDS)rsdl.o: $(CODES)rsdl.cpp $(CODES)rsdl.hpp 
	$(CC_OBJECT) $(CODES)rsdl.cpp -o $(BUILDS)rsdl.o


.PHONY: clean
clean:
	rm -r $(BUILDS)*.o starwars.out
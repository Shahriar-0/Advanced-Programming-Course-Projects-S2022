CC := g++ -std=c++11
SDLFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

all: star_wars.out

debug_star_wars.out: $(BUILDS)main.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)star_wars.o
	$(CC) $(BUILDS)*.o $(DEBUG) $(SDLFLAGS) -o debug_star_wars.out

starwars.out: $(BUILDS)main.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)star_wars.o
	$(CC) $(BUILDS)*.o $(SDLFLAGS) -o starwars.out

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)star_wars.hpp
	$(CC_OBJECT) $(CODES)main.cpp -o $(BUILDS)main.o

$(BUILDS)rsdl.o: $(CODES)rsdl.cpp $(CODES)rsdl.hpp 
	$(CC_OBJECT) $(CODES)rsdl.cpp -o $(BUILDS)rsdl.o

$(BUILDS)audio.o: $(CODES)audio.cpp $(CODES)audio.hpp
	$(CC_OBJECT) $(CODES)audio.cpp -o $(BUILDS)audio.o

$(BUILDS)star_wars.o: $(CODES)star_wars.hpp $(CODES)star_wars.cpp $(CODES)audio.hpp	
	$(CC_OBJECT) $(CODES)star_wars.cpp -o $(BUILDS)star_wars.o

.PHONY: clean
clean:
	rm -r $(BUILDS)*.o debug_star_wars.out starwars.out
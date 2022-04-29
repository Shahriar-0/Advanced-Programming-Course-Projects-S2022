CC := g++ -std=c++11
SDLFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

all: starwars.out

debug_star_wars.out: $(BUILDS)main.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)stationary_enemy.o $(BUILDS)moving_enemy.o $(BUILDS)enemies.o $(BUILDS)hostage.o $(BUILDS)star_wars.o $(BUILDS)bullet.o
	$(CC) $(BUILDS)*.o $(DEBUG) $(SDLFLAGS) -o debug_star_wars.out

starwars.out: $(BUILDS)main.o $(BUILDS)spaceship.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)stationary_enemy.o $(BUILDS)moving_enemy.o $(BUILDS)enemies.o $(BUILDS)hostage.o $(BUILDS)star_wars.o $(BUILDS)bullet.o
	$(CC) $(BUILDS)*.o $(SDLFLAGS) -o starwars.out

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)star_wars.hpp
	$(CC_OBJECT) $(CODES)main.cpp -o $(BUILDS)main.o

$(BUILDS)rsdl.o: $(CODES)rsdl.cpp $(CODES)rsdl.hpp 
	$(CC_OBJECT) $(CODES)rsdl.cpp -o $(BUILDS)rsdl.o

$(BUILDS)audio.o: $(CODES)audio.cpp $(CODES)audio.hpp
	$(CC_OBJECT) $(CODES)audio.cpp -o $(BUILDS)audio.o

$(BUILDS)star_wars.o: $(CODES)star_wars.hpp $(CODES)star_wars.cpp $(CODES)audio.hpp	
	$(CC_OBJECT) $(CODES)star_wars.cpp -o $(BUILDS)star_wars.o

$(BUILDS)bullet.o: $(CODES)bullet.cpp $(CODES)bullet.hpp
	$(CC_OBJECT) $(CODES)bullet.cpp $(BUILDS) -o $(BUILDS)bullet.o

$(BUILDS)hostage.o: $(CODES)hostage.cpp $(CODES)hostage.hpp
	$(CC_OBJECT) $(CODES)hostage.cpp -o $(BUILDS)hostage.o

$(BUILDS)enemies.o: $(CODES)enemies.cpp $(CODES)enemies.hpp $(CODES)moving_enemy.hpp
	$(CC_OBJECT) $(CODES)enemies.cpp -o $(BUILDS)enemies.o

$(BUILDS)moving_enemy.o: $(CODES)moving_enemy.cpp $(CODES)moving_enemy.hpp $(CODES)bullet.hpp
	$(CC_OBJECT) $(CODES)moving_enemy.cpp -o $(BUILDS)moving_enemy.o

$(BUILDS)stationary_enemy.o: $(CODES)stationary_enemy.cpp $(CODES)stationary_enemy.hpp $(CODES)bullet.hpp 
	$(CC_OBJECT) $(CODES)stationary_enemy.cpp -o $(BUILDS)stationary_enemy.o

$(BUILDS)spaceship.o: $(CODES)spaceship.cpp $(CODES)spaceship.hpp $(CODES)bullet.hpp $(CODES)bullet.hpp 
	$(CC_OBJECT) $(CODES)spaceship.cpp -o $(BUILDS)spaceship.o


.PHONY: clean
clean:
	rm -r $(BUILDS)*.o debug_star_wars.out starwars.out
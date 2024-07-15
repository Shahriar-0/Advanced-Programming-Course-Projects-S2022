CC := g++ --std=c++11
SDLFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

#let the dance be eternal
#it could have been hell lot better but I decided I rather help others than improving this one :)

all: starwars.out

debug.out: $(BUILDS)main.o $(BUILDS)moving_enemy.o $(BUILDS)stationary_enemy.o $(BUILDS)hostage.o $(BUILDS)enemies.o $(BUILDS)audio.o $(BUILDS)rsdl.o $(BUILDS)bullet.o $(BUILDS)star_wars.o $(BUILDS)space_ship.o $(BUILDS)my_space_ship.o
	$(CC) $(DEBUG) $(BUILDS)*.o $(SDLFLAGS) -o debug.out

starwars.out: $(BUILDS)main.o $(BUILDS)moving_enemy.o $(BUILDS)stationary_enemy.o $(BUILDS)hostage.o $(BUILDS)enemies.o $(BUILDS)audio.o $(BUILDS)rsdl.o $(BUILDS)bullet.o $(BUILDS)star_wars.o $(BUILDS)space_ship.o $(BUILDS)my_space_ship.o
	$(CC) $(BUILDS)*.o $(SDLFLAGS) -o starwars.out

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)star_wars.hpp
	$(CC_OBJECT) $(CODES)main.cpp -o $(BUILDS)main.o

$(BUILDS)star_wars.o: $(CODES)star_wars.cpp $(CODES)star_wars.hpp $(CODES)bullet.hpp $(CODES)my_space_ship.hpp $(CODES)audio.hpp
	$(CC_OBJECT) $(CODES)star_wars.cpp -o $(BUILDS)star_wars.o

$(BUILDS)space_ship.o: $(CODES)space_ship.cpp $(CODES)space_ship.hpp 
	$(CC_OBJECT) $(CODES)space_ship.cpp -o $(BUILDS)space_ship.o

$(BUILDS)my_space_ship.o: $(CODES)my_space_ship.cpp $(CODES)my_space_ship.hpp $(CODES)space_ship.hpp $(CODES)bullet.hpp
	$(CC_OBJECT) $(CODES)my_space_ship.cpp -o $(BUILDS)my_space_ship.o

$(BUILDS)enemies.o: $(CODES)enemies.cpp $(CODES)enemies.hpp $(CODES)audio.hpp $(CODES)bullet.hpp $(CODES)moving_enemy.hpp 
	$(CC_OBJECT) $(CODES)enemies.cpp -o $(BUILDS)enemies.o

$(BUILDS)hostage.o: $(CODES)hostage.cpp $(CODES)hostage.hpp $(CODES)stationary_enemy.hpp 
	$(CC_OBJECT) $(CODES)hostage.cpp -o $(BUILDS)hostage.o

$(BUILDS)stationary_enemy.o: $(CODES)stationary_enemy.cpp $(CODES)stationary_enemy.hpp $(CODES)my_space_ship.hpp  
	$(CC_OBJECT) $(CODES)stationary_enemy.cpp -o $(BUILDS)stationary_enemy.o

$(BUILDS)moving_enemy.o: $(CODES)moving_enemy.cpp $(CODES)moving_enemy.hpp $(CODES)stationary_enemy.hpp $(CODES)bullet.hpp 
	$(CC_OBJECT) $(CODES)moving_enemy.cpp -o $(BUILDS)moving_enemy.o

$(BUILDS)bullet.o: $(CODES)bullet.cpp $(CODES)bullet.hpp 
	$(CC_OBJECT) $(CODES)bullet.cpp -o $(BUILDS)bullet.o

$(BUILDS)audio.o: $(CODES)audio.cpp $(CODES)audio.hpp 
	$(CC_OBJECT) $(CODES)audio.cpp -o $(BUILDS)audio.o

$(BUILDS)rsdl.o: $(CODES)rsdl.cpp $(CODES)rsdl.hpp 
	$(CC_OBJECT) $(CODES)rsdl.cpp -o $(BUILDS)rsdl.o


.PHONY: clean_all clean_obj clean_exe help

clean_all:
	rm -r $(BUILDS)*.o starwars.out debug.out

clean_exe:
	rm -r starwars.out debug.out

clean_obj:
	rm -r $(BUILDS)*.o

run:
	./star_wars.out ./assets/maps/map.txt 

help:
	@echo Targets: all clean clean-obj clean-exe run
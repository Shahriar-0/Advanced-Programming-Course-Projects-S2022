CC := g++ -std=c++11
SDLFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

all: starwars.out

debug_star_wars.out: $(BUILDS)main.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)stationary_enemy.o $(BUILDS)moving_enemy.o $(BUILDS)stationary_enemies.o $(BUILDS)moving_enemies.o $(BUILDS)hostage.o $(BUILDS)star_wars.o $(BUILDS)my_bullet.o $(BUILDS)enemy_bullet.o
	$(CC) $(BUILDS)*.o $(DEBUG) $(SDLFLAGS) -o debug_star_wars.out

starwars.out: $(BUILDS)main.o $(BUILDS)rsdl.o $(BUILDS)audio.o $(BUILDS)stationary_enemy.o $(BUILDS)moving_enemy.o $(BUILDS)stationary_enemies.o $(BUILDS)moving_enemies.o $(BUILDS)hostage.o $(BUILDS)star_wars.o $(BUILDS)my_bullet.o $(BUILDS)enemy_bullet.o
	$(CC) $(BUILDS)*.o $(SDLFLAGS) -o starwars.out

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)star_wars.hpp
	$(CC_OBJECT) $(CODES)main.cpp -o $(BUILDS)main.o

$(BUILDS)rsdl.o: $(CODES)rsdl.cpp $(CODES)rsdl.hpp 
	$(CC_OBJECT) $(CODES)rsdl.cpp -o $(BUILDS)rsdl.o

$(BUILDS)audio.o: $(CODES)audio.cpp $(CODES)audio.hpp
	$(CC_OBJECT) $(CODES)audio.cpp -o $(BUILDS)audio.o

$(BUILDS)star_wars.o: $(CODES)star_wars.hpp $(CODES)star_wars.cpp $(CODES)audio.hpp	
	$(CC_OBJECT) $(CODES)star_wars.cpp -o $(BUILDS)star_wars.o

$(BUILDS)my_bullet.o: $(CODES)my_bullet.cpp $(CODES)my_bullet.hpp $(CODES)moving_enemies.hpp $(CODES)stationary_enemies.hpp $(CODES)hostage.hpp
	$(CC_OBJECT) $(CODES)my_bullet.cpp -o $(BUILDS)my_bullet.o

$(BUILDS)enemy_bullet.o: $(CODES)enemy_bullet.cpp $(CODES)enemy_bullet.hpp
	$(CC_OBJECT) $(CODES)enemy_bullet.cpp $(BUILDS) -o $(BUILDS)enemy_bullet.o

$(BUILDS)hostage.o: $(CODES)hostage.cpp $(CODES)hostage.hpp
	$(CC_OBJECT) $(CODES)hostage.cpp -o $(BUILDS)hostage.o

$(BUILDS)moving_enemies.o: $(CODES)moving_enemies.cpp $(CODES)moving_enemies.hpp $(CODES)moving_enemy.hpp
	$(CC_OBJECT) $(CODES)moving_enemies.cpp -o $(BUILDS)moving_enemies.o

$(BUILDS)stationary_enemies.o: $(CODES)stationary_enemies.cpp $(CODES)stationary_enemies.hpp $(CODES)moving_enemy.hpp
	$(CC_OBJECT) $(CODES)stationary_enemies.cpp -o $(BUILDS)stationary_enemies.o

$(BUILDS)moving_enemy.o: $(CODES)moving_enemy.cpp $(CODES)moving_enemy.hpp $(CODES)enemy_bullet.hpp
	$(CC_OBJECT) $(CODES)moving_enemy.cpp -o $(BUILDS)moving_enemy.o

$(BUILDS)stationary_enemy.o: $(CODES)stationary_enemy.cpp $(CODES)stationary_enemy.hpp $(CODES)enemy_bullet.hpp 
	$(CC_OBJECT) $(CODES)stationary_enemy.cpp -o $(BUILDS)stationary_enemy.o


.PHONY: clean
clean:
	rm -r $(BUILDS)*.o debug_star_wars.out starwars.out
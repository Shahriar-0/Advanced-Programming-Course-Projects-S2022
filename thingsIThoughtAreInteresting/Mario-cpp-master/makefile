CC := g++
CCFLAGS += -std=c++11 -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
DEBUG := -g
GAME := code/game
MAIN := code/main
VIEW := code/view
MAP_READER := code/map_reader

BLOCK := code/block
BONUS := code/bonus
GUMBA := code/gumba
KOOPA := code/koopa

MARIO := code/mario
VIEW := code/view
BG := code/background
SCOREBOARD := code/scoreboard
AUDIO := code/audio

DEFINES := code/defines.hpp
all: a.out

debug: main.o rsdl.o
	$(CC) *.o $(DEBUG) $(CCFLAGS) -o a.out

a.out: main.o rsdl.o
	$(CC) *.o $(CCFLAGS) -o a.out

main.o: src/rsdl.hpp $(MAIN).cpp game.o
	$(CC) -c $(MAIN).cpp

game.o: $(GAME).cpp $(GAME).hpp scoreboard.o audio.o view.o map_reader.o  mario.o $(DEFINES)
	$(CC) -c  $(GAME).cpp

map_reader.o:$(MAP_READER).cpp $(MAP_READER).hpp block.o bonus.o gumba.o koopa.o rsdl.o $(DEFINES)
		$(CC) -c  $(MAP_READER).cpp

block.o: $(BLOCK).cpp $(BLOCK).hpp $(DEFINES)
	$(CC) -c  $(BLOCK).cpp

bonus.o: $(BONUS).cpp $(BONUS).hpp $(DEFINES)
	$(CC) -c  $(BONUS).cpp

gumba.o: $(GUMBA).cpp $(GUMBA).hpp $(DEFINES)
	$(CC) -c  $(GUMBA).cpp

koopa.o: $(KOOPA).cpp $(KOOPA).hpp $(DEFINES)
	$(CC) -c  $(KOOPA).cpp

view.o: $(VIEW).cpp $(VIEW).hpp $(DEFINES) map_reader.o mario.o block.o background.o scoreboard.o
	$(CC) -c  $(VIEW).cpp

mario.o: $(MARIO).cpp $(MARIO).hpp audio.o $(DEFINES)
		$(CC) -c  $(MARIO).cpp

scoreboard.o: $(SCOREBOARD).cpp $(SCOREBOARD).hpp $(DEFINES)
		$(CC) -c  $(SCOREBOARD).cpp

background.o: $(BG).cpp $(BG).hpp
		$(CC) -c  $(BG).cpp

audio.o: $(AUDIO).cpp $(AUDIO).hpp
		$(CC) -c  $(AUDIO).cpp

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o a.out

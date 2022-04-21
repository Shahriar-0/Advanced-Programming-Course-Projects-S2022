FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
CC = g++ -std=c++11

all: game.out

game.out: Game.o Camera.o Map.o main.o CollisionHandler.o Mario.o LittleGoomba.o KoopaTroopa.o Sound.o BrickBlock.o QuestionBlock.o NormalBlock.o Flag.o Objects.o Pipe.o Mushroom.o
	$(CC) Game.o Camera.o Map.o main.o CollisionHandler.o Mario.o LittleGoomba.o KoopaTroopa.o Sound.o BrickBlock.o QuestionBlock.o NormalBlock.o Flag.o Objects.o Pipe.o Mushroom.o rsdl.cpp $(FLAGS) -o game.out

main.o: Game.h main.cpp
	$(CC) -c main.cpp $(FLAGS)

Game.o: Game.cpp Game.h Map.h Objects.h blockSize.h CollisionHandler.h Camera.h Sound.h
	$(CC) -c Game.cpp $(FLAGS)

Camera.o: Camera.cpp Camera.h 
	$(CC) -c Camera.cpp $(FLAGS)

Map.o: Map.h Map.cpp BrickBlock.h QuestionBlock.h KoopaTroopa.h LittleGoomba.h Game.h Objects.h Mario.h blockSize.h CollisionHandler.h
	$(CC) -c Map.cpp $(FLAGS)

Mario.o: Mario.h Mario.cpp blockSize.h Gravity.h MarioDefines.h Game.h Sound.h Camera.h
	$(CC) -c Mario.cpp $(FLAGS)

NormalBlock.o: NormalBlock.h NormalBlock.cpp blockSize.h
	$(CC) -c NormalBlock.cpp $(FLAGS)

QuestionBlock.o: QuestionBlock.cpp QuestionBlock.h blockSize.h
	$(CC) -c QuestionBlock.cpp $(FLAGS)

BrickBlock.o: BrickBlock.cpp BrickBlock.h blockSize.h
	$(CC) -c BrickBlock.cpp $(FLAGS)

Flag.o: Flag.h Flag.cpp blockSize.h
	$(CC) -c Flag.cpp $(FLAGS)

Objects.o: Objects.h Objects.cpp BrickBlock.h QuestionBlock.h KoopaTroopa.h LittleGoomba.h Flag.h Pipe.h NormalBlock.h blockSize.h
	$(CC) -c Objects.cpp $(FLAGS)

Pipe.o: Pipe.h Pipe.cpp blockSize.h
	$(CC) -c Pipe.cpp $(FLAGS)

KoopaTroopa.o: KoopaTroopa.h KoopaTroopa.cpp blockSize.h Gravity.h
	$(CC) -c KoopaTroopa.cpp $(FLAGS)

LittleGoomba.o: LittleGoomba.h LittleGoomba.cpp blockSize.h Gravity.h
	$(CC) -c LittleGoomba.cpp $(FLAGS)

CollisionHandler.o: CollisionHandler.h CollisionHandler.cpp Objects.h Game.h BrickBlock.h QuestionBlock.h KoopaTroopa.h LittleGoomba.h Flag.h Pipe.h NormalBlock.h
	$(CC) -c CollisionHandler.cpp $(FLAGS)

Mushroom.o: Mushroom.h Mushroom.cpp blockSize.h Gravity.h
	$(CC) -c Mushroom.cpp $(FLAGS)

Sound.o: Sound.h Sound.cpp Camera.h 
	$(CC) -c Sound.cpp $(FLAGS)

.PHONY: clean

clean:
	rm *.o
	rm game.out

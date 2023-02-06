#directories
CODES 		:= code/
BUILDS 		:= build/
NODES 		:= $(CODES)nodes/
CLI 		:= $(CODES)cli/
MANAGER 	:= $(CODES)manager/
PLAYER 		:= $(CODES)player/


#compile flags
CC 			:= g++ --std=c++11
DEBUG 		:= -g
CC_OBJECT 	:= $(CC) -c

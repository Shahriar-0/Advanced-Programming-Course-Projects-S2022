#directories
CODES 		:= code/
BUILDS 		:= build/
NODES 		:= $(CODES)nodes/
CLI 		:= $(CODES)cli/
MANAGER 	:= $(CODES)manager/
PLAYER 		:= $(CODES)player/


#compile flags
CC 			:= g++ --std=c++11
DEBUG 		:= $(CC) -g
CC_OBJECT 	:= $(CC) -c


MKDIR  		:= mkdir -p
RM     		:= rm -f
RMDIR  		:= rm -r
COPY   		:= cp
MOVE   		:= mv -f
RENAME 		:= mv -f
NULL_DEVICE := /dev/null
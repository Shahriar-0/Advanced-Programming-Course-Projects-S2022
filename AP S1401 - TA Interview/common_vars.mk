#compile flags
CC 			:= g++ --std=c++11
DEBUG 		:= -g
CC_OBJECT 	:= $(CC) -c

#directories
CODES 		:= code/
BUILDS 		:= build/
NODES 		:= $(CODES)nodes/
CLI 		:= $(CODES)cli/
MANAGER 	:= $(CODES)manager/
PLAYER 		:= $(CODES)player/


#working with files
ifeq ($(OS),Windows_NT)
	MKDIR  		:= mkdir
	RM     		:= del
	RMDIR  		:= rmdir /s /Q
	COPY   		:= copy /y
	MOVE   		:= move
	RENAME 		:= ren
	NULL_DEVICE := nul
else
	MKDIR  		:= mkdir -p
	RM     		:= rm -f
	RMDIR  		:= rm -r
	COPY   		:= cp
	MOVE   		:= mv -f
	RENAME 		:= mv -f
	NULL_DEVICE := /dev/null
endif

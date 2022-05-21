CC 			:= g++ --std=c++11
CC_OBJECT 	:= $(CC) -c
CC_DEBUG 	:= $(CC) -g



MKDIR  = mkdir -p
RM     = rm -f
RMDIR  = rm -rf
COPY   = cp
MOVE   = mv -f
RENAME = mv -f
NULL_DEVICE = /dev/null
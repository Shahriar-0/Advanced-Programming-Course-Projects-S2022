#compile flags
CC 			:= g++ --std=c++11
DEBUG 		:= -g
CC_OBJECT 	:= $(CC) -c

#directories
CODES 		:= codes/
BUILDS 		:= builds/
DATA 		:= $(CODES)datas/
ERROR 		:= $(CODES)error/
IO 			:= $(CODES)IO/
MANAGER 	:= $(CODES)manager/
REQUEST 	:= $(CODES)requests/


#working with files
MKDIR  		:= mkdir -p
RM     		:= rm -f
RMDIR  		:= rm -rf
COPY   		:= cp
MOVE   		:= mv -f
RENAME 		:= mv -f
NULL_DEVICE := /dev/null
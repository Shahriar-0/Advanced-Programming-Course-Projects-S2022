#compile vars
CC 			:= g++ --std=c++11 
CC_OBJECT 	:= $(CC) -c
CC_DEBUG 	:= $(CC) -g

#primitive folders
CODES		:= codes/
BUILDS      := builds/ 
ERROR 		:= $(CODES)error/
IO 			:= $(CODES)IO/
MAIN 		:= $(CODES)main/
MANAGER 	:= $(CODES)manager/
REQUEST 	:= $(CODES)request/

#data directories
DATA 		:= $(CODES)data/	
DATABASE 	:= $(DATA)database/
LOCATION 	:= $(DATA)location/
PEOPLE 		:= $(DATA)people/
TRIP 		:= $(DATA)trip/


#just to save myself a headache
BUILD_OBJECTS 	:= $(BUILDS)database.o $(BUILDS)location.o $(BUILDS)person.o $(BUILDS)driver.o $(BUILDS)passenger.o $(BUILDS)trip.o $(BUILDS)error_handler.o $(BUILDS)IO_handler.o $(BUILDS)main.o $(BUILDS)utaxi.o $(BUILDS)request.o $(BUILDS)delete_requst.o $(BUILDS)post_request.o $(BUILDS)get_request.o 
LOCATIONS_INPUT := assets/location.csv

#for working with files
MKDIR  		:= mkdir -p
RM     		:= rm -f
RMDIR  		:= rm -rf
COPY   		:= cp
MOVE   		:= mv -f
RENAME 		:= mv -f
NULL_DEVICE := /dev/null


#--------------------------------------------------------------


all: utaxi.out 

utaxi.out: $(BUILD_OBJECTS)
		$(CC) $(BUILD_OBJECTS) -o $@ 

debug.out: $(BUILD_OBJECTS)
		$(CC_DEBUG) $(BUILD_OBJECTS) -o $@

$(BUILDS)error_handler.o: $(ERROR)error_handler.cpp $(ERROR)error_handler.hpp
	$(CC_OBJECT) $(ERROR)error_handler.cpp -o $@

$(BUILDS)IO_handler.o: $(IO)IO_handler.cpp $(IO)IO_handler.hpp
	$(CC_OBJECT) $(IO)IO_handler.cpp -o $@

$(BUILDS)main.o: $(MAIN)main.cpp
	$(CC_OBJECT) $(MAIN)main.cpp -o $@

$(BUILDS)utaxi.o: $(MANAGER)utaxi.cpp $(MANAGER)utaxi.hpp
	$(CC_OBJECT) $(MANAGER)utaxi.cpp -o $@

$(BUILDS)request.o: $(REQUEST)request.cpp $(REQUEST)request.hpp
	$(CC_OBJECT) $(REQUEST)request.cpp -o $@

$(BUILDS)delete_requst.o: $(REQUEST)delete_requst.cpp $(REQUEST)delete_requst.hpp
	$(CC_OBJECT) $(REQUEST)delete_requst.cpp -o $@

$(BUILDS)post_request.o: $(REQUEST)post_request.cpp $(REQUEST)post_request.hpp
	$(CC_OBJECT) $(REQUEST)post_request -o $@

$(BUILDS)get_request.o: $(REQUEST)get_request.cpp $(REQUEST)get_request.hpp
	$(CC_OBJECT) $(REQUEST)get_request.cpp -o $@

$(BUILDS)database.o: $(DATABASE)database.cpp $(DATABASE)database.hpp
	$(CC_OBJECT) $(DATABASE)database.cpp -o $@

$(BUILDS)location.o: $(LOCATION)location.cpp $(LOCATION)location.hpp
	$(CC_OBJECT) $(LOCATION)location.cpp -o $@

$(BUILDS)person.o: $(PEOPLE)person.cpp $(PEOPLE)person.hpp
	$(CC_OBJECT) $(PEOPLE)person.cpp -o $@

$(BUILDS)driver.o: $(PEOPLE)driver.cpp $(PEOPLE)driver.hpp
	$(CC_OBJECT) $(PEOPLE)driver.cpp -o $@

$(BUILDS)passenger.o: $(PEOPLE)passenger.cpp $(PEOPLE)passenger.hpp
	$(CC_OBJECT) $(PEOPLE)passenger.cpp -o $@

$(BUILDS)trip.o: $(TRIP)trip.cpp $(TRIP)trip.hpp
	$(CC_OBJECT) $(TRIP)trip.cpp -o $@

#---------------------------------------------------------

.PHONY: all clean run

clean: 
	$(RM) $(BUILDS)/*.o
	$(RM) utaxi.out debug.out > $(NULL_DEVICE)

run: ./utaxi.out $(LOCATIONS_INPUT)
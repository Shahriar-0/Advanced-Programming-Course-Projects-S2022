CC := g++ --std=c++11
DEBUG := -g
CC_OBJECT := $(CC) -c
CODES := codes/
BUILDS := builds/

#let the dance be eternal

all: utaxi.out

debug.out: $(BUILDS)main.o $(BUILDS)get_request.o $(BUILDS)request.o $(BUILDS)trip.o $(BUILDS)post_request.o $(BUILDS)IO_handler.o $(BUILDS)location.o $(BUILDS)passenger.o $(BUILDS)person.o $(BUILDS)utaxi.o $(BUILDS)database.o $(BUILDS)delete_request.o $(BUILDS)driver.o $(BUILDS)error_handler.o
	$(CC) $(DEBUG) $(BUILDS)*.o -o $@

utaxi.out: $(BUILDS)main.o $(BUILDS)get_request.o $(BUILDS)request.o $(BUILDS)trip.o $(BUILDS)post_request.o $(BUILDS)IO_handler.o $(BUILDS)location.o $(BUILDS)passenger.o $(BUILDS)person.o $(BUILDS)utaxi.o $(BUILDS)database.o $(BUILDS)delete_request.o $(BUILDS)driver.o $(BUILDS)error_handler.o
	$(CC) $(BUILDS)*.o -o $@

$(BUILDS)main.o: $(CODES)main.cpp $(CODES)utaxi.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)utaxi.o: $(CODES)utaxi.cpp $(CODES)utaxi.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)database.o: $(CODES)database.cpp $(CODES)database.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)delete_request.o: $(CODES)delete_request.cpp $(CODES)delete_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)driver.o: $(CODES)driver.cpp $(CODES)driver.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)error_handler.o: $(CODES)error_handler.cpp $(CODES)error_handler.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)get_request.o: $(CODES)get_request.cpp $(CODES)get_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)IO_handler.o: $(CODES)IO_handler.cpp $(CODES)IO_handler.hpp
	$(CC_OBJECT) $< -o $@
$(BUILDS)location.o: $(CODES)location.cpp $(CODES)location.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)passenger.o: $(CODES)passenger.cpp $(CODES)passenger.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)person.o: $(CODES)person.cpp $(CODES)person.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)post_request.o: $(CODES)post_request.cpp $(CODES)post_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)request.o: $(CODES)request.cpp $(CODES)request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)trip.o: $(CODES)trip.cpp $(CODES)trip.hpp
	$(CC_OBJECT) $< -o $@

#----------------------------------------------------------------
.PHONY: clean clean_obj clean_exe help

clean:
	rm -r $(BUILDS)*.o utaxi.out debug.out

clean_exe:
	rm -r utaxi.out debug.out

clean_obj:
	rm -r $(BUILDS)*.o

run:
	./utaxi.out location.csv 

help:
	@echo Targets: all clean clean-obj clean-exe run
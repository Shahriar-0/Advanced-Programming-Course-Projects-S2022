include common_vars.mk
#let the dance be eternal

all: utaxi.out

debug.out: $(BUILDS)main.o $(BUILDS)get_request.o $(BUILDS)system_request.o $(BUILDS)template_parser.o $(BUILDS)handlers.o $(BUILDS)response.o $(BUILDS)request.o $(BUILDS)utilities.o $(BUILDS)server.o $(BUILDS)route.o $(BUILDS)trip.o $(BUILDS)post_request.o $(BUILDS)IO_handler.o $(BUILDS)location.o $(BUILDS)passenger.o $(BUILDS)person.o $(BUILDS)utaxi.o $(BUILDS)database.o $(BUILDS)delete_request.o $(BUILDS)driver.o $(BUILDS)error_handler.o
	$(CC) $(DEBUG) $(BUILDS)*.o -o $@

utaxi.out: $(BUILDS)main.o $(BUILDS)get_request.o $(BUILDS)system_request.o $(BUILDS)template_parser.o $(BUILDS)handlers.o $(BUILDS)response.o $(BUILDS)request.o $(BUILDS)utilities.o $(BUILDS)server.o $(BUILDS)route.o $(BUILDS)trip.o $(BUILDS)post_request.o $(BUILDS)IO_handler.o $(BUILDS)location.o $(BUILDS)passenger.o $(BUILDS)person.o $(BUILDS)utaxi.o $(BUILDS)database.o $(BUILDS)delete_request.o $(BUILDS)driver.o $(BUILDS)error_handler.o
	$(CC) $(BUILDS)*.o -o $@

#managing part
$(BUILDS)main.o: $(MANAGER)main.cpp $(MANAGER)utaxi.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)utaxi.o: $(MANAGER)utaxi.cpp $(MANAGER)utaxi.hpp
	$(CC_OBJECT) $< -o $@

#datas
$(BUILDS)database.o: $(DATA)database.cpp $(DATA)database.hpp
	$(CC_OBJECT) $< -o $@
	
$(BUILDS)location.o: $(DATA)location.cpp $(DATA)location.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)passenger.o: $(DATA)passenger.cpp $(DATA)passenger.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)person.o: $(DATA)person.cpp $(DATA)person.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)trip.o: $(DATA)trip.cpp $(DATA)trip.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)driver.o: $(DATA)driver.cpp $(DATA)driver.hpp
	$(CC_OBJECT) $< -o $@

#error
$(BUILDS)error_handler.o: $(ERROR)error_handler.cpp $(ERROR)error_handler.hpp
	$(CC_OBJECT) $< -o $@

#requests
$(BUILDS)delete_request.o: $(REQUEST)delete_request.cpp $(REQUEST)delete_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)get_request.o: $(REQUEST)get_request.cpp $(REQUEST)get_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)post_request.o: $(REQUEST)post_request.cpp $(REQUEST)post_request.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)system_request.o: $(REQUEST)request.cpp $(REQUEST)request.hpp
	$(CC_OBJECT) $< -o $@

#IO
$(BUILDS)IO_handler.o: $(IO)IO_handler.cpp $(IO)IO_handler.hpp
	$(CC_OBJECT) $< -o $@

#sever
$(BUILDS)template_parser.o: $(UTILS)template_parser.cpp $(UTILS)template_parser.hpp $(UTILS)request.cpp $(UTILS)request.hpp $(UTILS)utilities.hpp $(UTILS)utilities.cpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)response.o: $(UTILS)response.cpp $(UTILS)response.hpp $(UTILS)include.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)request.o: $(UTILS)request.cpp $(UTILS)request.hpp $(UTILS)include.hpp $(UTILS)utilities.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)utilities.o: $(UTILS)utilities.cpp $(UTILS)utilities.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)server.o: $(SERVER)server.cpp $(SERVER)server.hpp $(SERVER)route.hpp $(UTILS)utilities.hpp $(UTILS)response.hpp $(UTILS)request.hpp $(UTILS)include.hpp $(UTILS)template_parser.hpp $(UTILS)template_parser.cpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)route.o: $(SERVER)route.cpp $(SERVER)route.hpp $(UTILS)utilities.hpp $(UTILS)response.hpp $(UTILS)request.hpp $(UTILS)include.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)handlers.o: $(HANDLERS)handlers.cpp $(SERVER)server.hpp $(UTILS)utilities.hpp $(UTILS)response.hpp $(UTILS)request.hpp $(UTILS)include.hpp
	$(CC_OBJECT) $< -o $@

#----------------------------------------------------------------
.PHONY: clean clean_obj clean_exe help

clean:
	rm -r $(BUILDS)*.o utaxi.out debug.out 2> $(NULL_DEVICE)

clean_exe:
	rm -r utaxi.out debug.out 2> $(NULL_DEVICE)

clean_obj:
	rm -r $(BUILDS)*.o 2> $(NULL_DEVICE)

run:
	./utaxi.out location.csv 

help:
	@echo Targets: all clean clean-obj clean-exe run
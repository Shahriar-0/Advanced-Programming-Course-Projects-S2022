#well, if it doesn't matter, can I stay with you on the phone at least?
include common_vars.mk

#------------------------- TARGETS ------------------------------

all: interview.out

debug.out: $(BUILDS)main.o $(BUILDS)game_manager.o $(BUILDS)node.o $(BUILDS)game_station.o $(BUILDS)queue_node.o $(BUILDS)armwrestler.o $(BUILDS)chess.o $(BUILDS)wrestler.o $(BUILDS)kabab.o $(BUILDS)cli.o $(BUILDS)player.o 
	$(DEBUG) $(BUILDS)*.o -o $@

interview.out: $(BUILDS)main.o $(BUILDS)game_manager.o $(BUILDS)node.o $(BUILDS)game_station.o $(BUILDS)queue_node.o $(BUILDS)armwrestler.o $(BUILDS)chess.o $(BUILDS)wrestler.o $(BUILDS)kabab.o $(BUILDS)cli.o $(BUILDS)player.o 
	$(CC) $(BUILDS)*.o -o $@


#------------------------- OBJECTS ------------------------------

#managing part
$(BUILDS)main.o: $(MANAGER)main.cpp 
	$(CC_OBJECT) $< -o $@

$(BUILDS)game_manager.o: $(MANAGER)game_manager.cpp $(MANAGER)game_manager.hpp
	$(CC_OBJECT) $< -o $@

#nodes 
$(BUILDS)node.o: $(NODES)node.cpp $(MANAGER)node.hpp $(PLAYER)player.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)game_station.o: $(NODES)game_station.cpp $(NODES)game_station.hpp $(MANAGER)node.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)queue_node.o: $(NODES)queue_node.cpp $(NODES)queue_node.hpp $(MANAGER)node.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)armwrestler.o: $(NODES)armwrestler.cpp $(NODES)armwrestler.hpp $(NODES)game_station.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)chess.o: $(NODES)chess.cpp $(NODES)chess.hpp $(NODES)game_station.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)wrestler.o: $(NODES)wrestler.cpp $(NODES)wrestler.hpp $(NODES)game_station.hpp
	$(CC_OBJECT) $< -o $@

$(BUILDS)kabab.o: $(NODES)kabab.cpp $(NODES)kabab.hpp $(NODES)game_station.hpp
	$(CC_OBJECT) $< -o $@

#cli
$(BUILDS)cli.o: $(CLI)cli.cpp $(CLI)cli.hpp $(MANAGER)game_manager.hpp
	$(CC_OBJECT) $< -o $@

#player
$(BUILDS)player.o: $(PLAYER)player.cpp $(PLAYER)player.hpp $(MANAGER)game_manager.hpp
	$(CC_OBJECT) $< -o $@


#------------------------- PHONYS  ------------------------------

.PHONY: clean clean_objs clean_exe help

help:
	@echo Targets: all clean clean-objs clean-exe run

clean:
	$(RM) $(BUILDS)*.o interview.out debug.out 2> $(NULL_DEVICE)

clean_objs:
	$(RM) $(BUILDS)*.o 2> $(NULL_DEVICE)

clean_exe:
	$(RM) interview.out debug.out 2> $(NULL_DEVICE)

run:
	./interview.out 
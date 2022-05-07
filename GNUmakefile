# by default, make will try to build the first target it encounters.
# here we make up a dummy name "ALL" (note: this is not a special make
# name, it is just commonly used).

ALL: wordle_game

# find all of the source files and header files

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create a list of object files by replacing .cpp with .o

OBJECTS := $(SOURCES:.cpp=.o)

# we have 2 targets here, which means two main() functions.  We need
# to exclude these from the general list of sources / objects, so we
# filter them out
MAINS := wordle_game.o unit_test_wordle.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# by default, debug mode will be disabled
DEBUG ?= FALSE

CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

ifeq (${DEBUG}, TRUE)
   CXXFLAGS += -g
else
   CXXFLAGS += -DNDEBUG -O3
endif

# general rule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<


# explicitly write the rule for linking together the executable

wordle_game: wordle_game.o ${OBJECTS}
	g++ -o $@ ${OBJECTS}

# make unit test
unit_test_wordle: unit_test_wordle.o ${OBJECTS}
	g++ -o $@ ${OBJECTS}

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o wordle_game

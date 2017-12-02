CC=g++
CFLAGS= -g
OBJ= characters.o tree.o dictionnary.o
SOURCE_FILES = hpcompressor.cpp
EXEC=hpcompressor
TEST_SOURCE = $(wildcard test_*.cpp)
RM_TEST = $(basename $(TEST_SOURCE))

all: $(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $@ $(SOURCE_FILES) $(OBJ)
	
.cpp.o:
	$(CC) -c $< -o $@

test: $(TEST_SOURCE)

$(TEST_SOURCE): $(OBJ)
	$(CC) -o $(basename $@) $@ $^

clear:
	rm -f *.o $(EXEC) $(RM_TEST)



	

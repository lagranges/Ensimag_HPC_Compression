CC=g++
CFLAGS= -g
OBJ= characters.o tree.o dictionnary.o compressor.o
SOURCE_FILES = hpcompressor.cpp
EXEC=hpcompressor
TEST_SOURCE = $(wildcard test_*.cpp)
RM_TEST = $(basename $(TEST_SOURCE))

all: $(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $@ $(SOURCE_FILES) $(OBJ) -fopenmp
	
.cpp.o:
	$(CC) -c $< -o $@ -fopenmp

test: $(TEST_SOURCE)

$(TEST_SOURCE): $(OBJ)
	$(CC) -o $(basename $@) $@ $^ -fopenmp 

clear:
	rm -f *.o $(EXEC) $(RM_TEST)



	

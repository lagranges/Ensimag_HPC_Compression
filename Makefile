CC=g++
CFLAGS= -g
OBJ= characters.o tree.o
SOURCE_FILES = hpcompressor.cpp
EXEC=hpcompressor
TEST_SOURCE = test_*.cpp

all: $(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $@ $(SOURCE_FILES) $(OBJ)
	
.cpp.o:
	$(CC) -c -Wall $< -o $@

test: $(TEST_SOURCE)

$(TEST_SOURCE): $(OBJ)
	$(CC) -o $(basename $@) $@ $^

clear:
	rm -f *.o $(EXEC) $(basename $(TEST_SOURCE))

	

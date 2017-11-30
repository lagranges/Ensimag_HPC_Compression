
CFLAGS = -c -Wall

SRC_PACKAGES = dico.hpp dico.cpp \
               code_binary.hpp code_binaire.cpp \
               file_priority.hpp file_priority.cpp \
               tree.hpp tree.cpp
Test_tree = tree.hpp tree.cpp

EXE = hpcompressor test_file test_code test_tree test_dico


all: $(EXE)

hpcompressor: main_huffman.cpp $(SRC_PACKAGES)
	g++ $(CFLAGS) $@

test_file: test_file.cpp $(SRC_PACKAGES)
	g++ $(CFLAGS) $@

test_tree: test_tree.cpp $(Test_tree)
	g++ $(CFLAGS) $< -o $@

test_code: test_code.cpp $(SRC_PACKAGES)
	g++ $(CFLAGS) $@

test_dico: test_dico.cpp $(SRC_PACKAGES)
	g++ $(CFLAGS) $@

clean:
	rm -f b~* ~*

cleanall: clean
	rm -f $(EXE) 
	

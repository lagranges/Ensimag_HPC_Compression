
CFLAGS = -g	

SRC_PACKAGES = dico.hpp dico.cpp \
               code_binary.hpp code_binaire.cpp \
               file_priority.hpp file_priority.cpp \
               tree.hpp tree.cpp

EXE = hpcompressor test_file test_code test_tree test_dico


all: $(EXE)

hpcompressor: main_huffman.adb $(SRC_PACKAGES)
	gcc $(CFLAGS) $@

test_file: test_file.adb $(SRC_PACKAGES)
	gcc $(CFLAGS) $@

test_tree: test_tree.adb $(SRC_PACKAGES)
	gcc $(CFLAGS) $@

test_code: test_code.adb $(SRC_PACKAGES)
	gcc $(CFLAGS) $@

test_dico: test_dico.adb $(SRC_PACKAGES)
	gcc $(CFLAGS) $@

clean:
	rm -f b~* ~*

cleanall: clean
	rm -f $(EXE) 
	

    # Parallel Compression using Huffman coding

    # High Performance Computing Project

    ## Introduction
        
        The project is implemted in C++ using, Open MPI.
        Input: a txt file/ a comp file (.comp is the extension of 
                                                            compressed file)
        Output: a comp file/ a txt file

    ## Files
        
        Source code (*.cpp, *.hpp)
        This README
        Makefile

    ## Compilation and Test Execution 
        For execute some unit_test:
            make test
            ./test_* For example ./test_tree
        For compress/decompress a file:
            make
            ./hpcompressor -c file_name compressed_file_name 
            (example ./hpcompressor -c Tests/francais.txt francais.txt.comp)
            ./main_huffman -d file_name compressed_file_name
            (example ./hpcompressor -d francais.txt.comp francais.txt.comp.txt)
        For checking:
            cd Test
            ./tests_huffman.sh nom_fichier
    ## Authors
        Ondre
        Tuan


    
    

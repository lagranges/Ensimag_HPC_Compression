# Parallel Compression using Huffman coding

# High Performance Computing Project

## Introduction

The project is implemted in C++ using, Open MPI.
Input: a txt file/ a comp file (.comp is the extension of compressed file)
Output: a comp file/ a txt file

## Files
        
Source code (*.cpp, *.hpp)
This README
Makefile

## Compilation and Test Execution 

For executing the unit_tests:
```
make test
./test_* 
```
* For example ./test_tree

For compressing/decompressing a file:
```
make
./hpcompressor -c file_name compressed_file_name 
```
* For example 
```
./hpcompressor -c Tests/francais.txt francais.txt.comp)
```
For checking the result:
```
cd Test
./tests_huffman.sh file_name
```
## Authors
* BOROVEC Ondrej 
* LE Van Tuan 

    
    

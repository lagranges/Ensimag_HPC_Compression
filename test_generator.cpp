#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
    if(argc<3){
        printf("Wrong syntax!");
        printf("Please use the following syntax:");
        printf("\t./test_generator file_size_in_kb filename ");
        printf("\t ex:./test_generator 100 txt_file");
    }
    string name = ((string) argv[2])+".txt";
    int i,size = atoi(((string)argv[1]).c_str())*1024*1024;
    char c;
    ofstream file;
    file.open(name.c_str());
    for(i=0;i<size;i++){
        c =' '+ (rand() % 94);
        if(i%80==0)
            file << "\n";
        else
            file << c;
    }
    printf("Text of %d mb has generated \n", size/1024/1024);
    return 0;
}

#include "compressor.hpp"
#include "time.h"

int main(int argc, char* argv[]){
    
    if(argc < 4)
        cout << "Usage: \n \t hpcompressor -c compressed_file_name decompressed_file_name \n \t hpcompressor -d decompressed_file_name compressed_file"<< endl;

    if(argv[1][0] == '-' && argv[1][1]== 'c') {
        Compressor comp = Compressor(argv[2]);
        struct timespec start, finish;
        double elapsed;
        clock_gettime(CLOCK_MONOTONIC, &start);
        comp.generate(argv[3]);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec -start.tv_sec);
        elapsed += (finish.tv_nsec -start.tv_nsec)/1000000000.0;
        cout << "Encoding time: " << elapsed<< endl;
    }

    //Compressor comp = Compressor("mini.txt");
    //Compressor comp = Compressor("shakespeare.txt");
    //comp.display();
    else if(argv[1][0] == '-' && argv[1][1]== 'd') {
        Decompressor decomp = Decompressor(argv[2]);
        struct timespec start, finish;
        double elapsed;
        clock_gettime(CLOCK_MONOTONIC, &start);
        decomp.generate(argv[3]);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec -start.tv_sec);
        elapsed += (finish.tv_nsec -start.tv_nsec)/1000000000.0;
        cout << "Decoding time: " << elapsed<< endl;
    }
    else {
        cout << "Usage: \n \t hpcompressor -c compressed_file_name decompressed_file_name \n \t hpcompressor -d decompressed_file_name compressed_file"<< endl;
    }
    //comp = Compressor("sample.txt");
    //comp.generate("result_comp");
    //comp.display();
    //decomp = Decompressor("result_comp.comp");
    //decomp.generate("result_comp");
}

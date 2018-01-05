#include "compressor.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4)
        cout << "Usage: \n \t hpcompressor -c compressed_file_name decompressed_file_name \n \t hpcompressor -d decompressed_file_name compressed_file"<< endl;

    if(argv[1][0] == '-' && argv[1][1]== 'c') {
        Compressor comp = Compressor(argv[2]);
        comp.generate(argv[3]);
    }

    //Compressor comp = Compressor("mini.txt");
    //Compressor comp = Compressor("shakespeare.txt");
    //comp.display();
    else if(argv[1][0] == '-' && argv[1][1]== 'd') {
        Decompressor decomp = Decompressor(argv[2]);
        decomp.generate(argv[3]);
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

#include "compressor.hpp"

int main(){
    
    Compressor comp = Compressor("sample.txt");
    comp.generate("result_comp");
    //comp.display();
    Decompressor decomp = Decompressor("result_comp.comp");
    decomp.generate("result_comp");
}
#include "compressor.hpp"

int main(){
    
    //Compressor comp = Compressor("sample.txt");
    //Compressor comp = Compressor("mini.txt");
    Compressor comp = Compressor("shakespeare.txt");
    comp.generate("result_comp.comp");
    //comp.display();
    Decompressor decomp = Decompressor("result_comp.comp");
    decomp.generate("result_comp.txt");
    
    //comp = Compressor("sample.txt");
    //comp.generate("result_comp");
    //comp.display();
    //decomp = Decompressor("result_comp.comp");
    //decomp.generate("result_comp");
}

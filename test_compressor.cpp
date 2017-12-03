#include "compressor.hpp"

int main(){
    

    Compressor comp = Compressor("mini.txt");
    comp.generate("mini_comp.comp");
    comp.display("mini_comp.comp");
}
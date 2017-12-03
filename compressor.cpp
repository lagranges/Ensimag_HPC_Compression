#include "compressor.hpp"

Compressor::Compressor(string f){
    file_name = f;
    chars = Characters("mini.txt");
    Tree *t = new Tree(chars);
    dict = Dictionnary(*t);
}

void Compressor::generate(string compressed_file)
{
    ifstream input_file;
    ofstream output_file;
    input_file.open(file_name);
    output_file.open(compressed_file+".comp");
    BinaryCode binary_code ;
    char ch, ctemp;
    cout << "[TEST] Expected Binary codes:" << endl;    
    while(input_file.get(ch))
    {
        binary_code += dict.get_binary_code(ch);
        while(binary_code.get_list().size()>=8){
            ctemp = binary_code.get_one_byte();
            output_file << ctemp;
        }
    }
    output_file << binary_code.get_one_byte();
    cout << endl;
    input_file.close(); 
    output_file.close();
}

void Compressor::display(string compressed_file)
{
    ifstream input_file;
    input_file.open(compressed_file);
    char ch;
    int n;
    cout << compressed_file << " display (in binary): " << endl;
    while(input_file.get(ch))
    {
        n = (int) ch;
        for(int i=7; i>=0;i--){
            cout << ((n>>i)&1) ;
        }
    }
    cout << "\nEnd of file display" << endl;
}

Decompressor::Decompressor(string f)
{
    file_name = f;
}

void Decompressor::generate(string decompressed_file)
{

}

void Decompressor::display(string decompressed_file)
{
    
}
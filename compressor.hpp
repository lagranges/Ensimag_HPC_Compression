#ifndef COMPRESSOR_INCLUDED
#define COMPRESSOR_INCLUDED

#include "dictionnary.hpp"

class Generic
{
    protected:
        Dictionnary dict;
        Characters chars;
        Tree tree;
        string file_name;
        string compressed_file;
    public:
        virtual void generate(string result_file_name) = 0;
};

class Compressor: public Generic
{
    
    public:
        Compressor(){};
        ~Compressor(){};
        Compressor(string file_name);
        virtual void generate(string compressed_file);
        // display compressed under binary codes
        void display();
};

class Decompressor: public Generic
{
    
    public:
        Decompressor(){};
        ~Decompressor(){};
        Decompressor(string file_name);
        virtual void generate(string decompressed_file);
        void display(string decompressed_file);
};
#endif 


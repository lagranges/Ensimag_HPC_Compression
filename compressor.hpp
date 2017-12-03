#ifndef COMPRESSOR_INCLUDED
#define COMPRESSOR_INCLUDED

#include "dictionnary.hpp"

class Generic
{
    protected:
        Dictionnary dict;
        Characters chars;
        string file_name;
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
        void display(string compressed_file);
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


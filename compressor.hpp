#ifndef COMPRESSOR_INCLUDED
#define COMPRESSOR_INCLUDED

#include "dictionnary.hpp"

#define N_THREAD 32

struct chunk{
    int id;
    long long int nb_chars;
    long long int nb_bytes;
    long long int i_chars;
    long long int i_bytes;
    long long int milestone_chars;
    long long int milestone_bytes;
    chunk(int idt,long long int nb_charst, long long int nb_bytest, long long int milestone_charst, long long int milestone_bytest):
        id(idt), nb_chars(nb_charst), nb_bytes(nb_bytest), i_chars(0)
    , i_bytes(0), milestone_chars(milestone_charst), milestone_bytes(milestone_bytest){}

    void display(){
        cout << " Chunk "<< id  << " nb_chars " << nb_chars << " nb_bytes " << nb_bytes << " milestone_chars "<< milestone_chars << " milestone_bytes " << milestone_bytes << endl;
    }
    void set_milestone_bytes(long long int m){
        milestone_bytes = m;   
    }
    void set_milestone_chars(long long int m){
        milestone_chars = m;   
    }
};

class Generic
{
    protected:
        Dictionnary dict;
        Characters chars;
        Tree tree;
        string file_name;
        string compressed_file;
        chunk *chunks[N_THREAD];
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


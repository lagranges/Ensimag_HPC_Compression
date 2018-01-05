#ifndef DICTIONNARY_INCLUDED
#define DICTIONNARY_INCLUDED

#include <map>
#include "tree.hpp"
#include <deque>

using namespace std;

enum BIT {zero = 0, one = 1};

class BinaryCode
{
    private: 
        deque<BIT> list;
    public: 
        BinaryCode(){};
        ~BinaryCode(){};
        BinaryCode(deque<BIT> l):list(l){}; 
        BinaryCode(char c);
        deque<BIT> get_list(){return list;};
        int size(){return list.size();};
        void push_back(BIT b){list.push_back(b); };
        void display();
        void operator+=(const BinaryCode& b);
        bool is_equal(BinaryCode const& b) const;
        char get_first_char(Tree tree);
        // remove 8 first bits
        char get_one_byte();
};

class Dictionnary
{
    private:
        map<char, BinaryCode> dict;
    public:
        Dictionnary(){};
        ~Dictionnary(){};
        Dictionnary(Tree tree);
        void display();
        BinaryCode get_binary_code(char c){return dict[c];};
        char get_char(BinaryCode bc);
};

#endif

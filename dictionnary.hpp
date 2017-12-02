#ifndef DICTIONNARY_INCLUDED
#define DICTIONNARY_INCLUDED

#include <map>
#include "tree.hpp"
#include <deque>

using namespace std;

enum BIT {zero = 0, one = 1};

class Dictionnary
{
    private:
        map<char, deque<BIT> > dict;
    public:
        Dictionnary(){};
        ~Dictionnary(){};
        Dictionnary(Tree tree);
        void display();
};

#endif
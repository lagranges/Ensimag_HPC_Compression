#ifndef CHARACTERS_INCLUDED
#define CHARACTERS_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

// represent a character that occurs in the text
// contains the character and its frequence
class Unit{

    public:
        Unit() {};
        ~Unit(){};
        Unit(char c1, long nb) { c = c1; nb_presence = nb;}
        bool operator<(const Unit&) const;

        char get_char() const { return c;}
        long get_nb_presence() const {return nb_presence;}
    private:
        // its character
        char c;
        // the number of occurence of the char
        long nb_presence;
};

class Characters{

    private:
        // The final purpose is updating pq
        // pq will be used to gererate Tree
        priority_queue<Unit> pq;
        
    public:
        Characters(){};
        ~Characters(){};
        // Create a map (char -> nb of occurence) 
        // of a text of name "file_name"
        Characters(string file_name);
        priority_queue<Unit> get_frequencies(){return pq;}
        void display();
        
};
#endif 
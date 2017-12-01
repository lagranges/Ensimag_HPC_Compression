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
        Unit *left, *right;
};

struct node{
    char val;
    long nb_occurs;
    node* left;
    node* right;
    bool operator<(const node& right) const
    {
        return nb_occurs > right.nb_occurs;
    }

    node(): val(NULL), nb_occurs(NULL), left(NULL), right(NULL){}
    node(char v, long nb, node* l, node* r):
        val(v), nb_occurs(nb), left(l), right(r){}
    node(const node& n): val(n.val), nb_occurs(n.nb_occurs),
    left(n.left), right(n.right){}

    void display()
    {
        if(left != NULL) 
            left->display();
        // if(val != NULL)
            printf("  [%c, %ld]", val, nb_occurs);
        if(right != NULL) 
            right->display();
    }
};
class Characters{

    private:
        priority_queue<node> pq;
        // The final purpose is updating pq
        // pq will be used to gererate Tree
        // priority_queue<Unit> pq;
        
    public:
        Characters(){};
        ~Characters(){};
        // Create a map (char -> nb of occurence) 
        // of a text of name "file_name"
        Characters(string file_name);
        priority_queue<node> get_frequencies(){return pq;}
        void display();
        
};
#endif 
#ifndef CHARACTERS_INCLUDED
#define CHARACTERS_INCLUDED

#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

// represent a node with its priority
// case particular, represent a character that occurs in the text
// contains the character and its frequence
struct node{
    char val;
    long long int nb_occurs;
    node* left;
    node* right;
    bool operator<(const node& right) const
    {
        return (nb_occurs > right.nb_occurs)
                || ( nb_occurs == right.nb_occurs && val > right.val);
    }

    node(): val('\0'), nb_occurs(0), left(NULL), right(NULL){}
    node(char v, long long int nb, node* l, node* r):
        val(v), nb_occurs(nb), left(l), right(r){}
    node(const node& n): val(n.val), nb_occurs(n.nb_occurs),
    left(n.left), right(n.right){}

    void display()
    {
        if(left != NULL) 
            left->display();
        // if(val != )
            printf("  [%c, %lld, %d, %d]", val, nb_occurs, this->depth(), this->is_leaf());
        if(right != NULL) 
            right->display();
    }

    int depth()
    {
        if(left == NULL && right == NULL) return 1;
        int left_depth=0, right_depth=0;
        if(left!=NULL)  left_depth = left->depth();
        if(right!=NULL)  right_depth = right->depth();
        return( 1+ 
            ((left_depth>right_depth)?left_depth:right_depth));
    }

    bool is_leaf(){
        return (left==NULL && right==NULL);
    }
};

class Characters{

    private:
        // The final purpose is updating pq
        // pq will be used to gererate Tree
        priority_queue<node> pq;
        long long int nb_chars;
    public:
        Characters(){};
        ~Characters(){};
        // Create a map (node -> nb of occurence) 
        // of a text of name "file_name"
        Characters(string file_name);
        Characters(priority_queue<node> pqt):pq(pqt){}; 
        priority_queue<node> get_frequencies(){return pq;}
        void display();
        long long int get_nb_chars(){return nb_chars;}
        void set_nb_chars(long long int nb){ nb_chars = nb;}
        
};
#endif 
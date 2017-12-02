#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include <iostream>
#include "characters.hpp"

using namespace std;

class Tree 
{
    private:
        char val;
        node *root;

    public:
        Tree(){};
        ~Tree(){};
        // Create a Leaf whose val is c
        Tree(node *u);
        
        // Create a tree from its two childrens
        // Tree(Tree *left, Tree *right);

        // Create a tree from a characters frequencies
        Tree(Characters characters);

        char get_val(){return val;}
        node* get_root(){return root;}
        // Get tree information
        void display();

};

#endif 

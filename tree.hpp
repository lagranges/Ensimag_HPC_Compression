#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include <iostream>
#include "characters.hpp"

using namespace std;

class Tree 
{
    private:
        char val;
        Tree *left, *right;

    public:
        Tree(){};
        ~Tree(){};
        // Create a Leaf whose val is c
        Tree(char c);
        
        // Create a tree from its two childrens
        Tree(Tree *left, Tree *right);

        // Create a tree from a characters frequencies
        Tree(Characters characters);

        // Get tree information
        void display();
};

#endif 

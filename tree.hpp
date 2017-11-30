#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include <iostream>

using namespace std;

class Tree 
{
    private:
        char val;
        Tree *childLeft, *childRight;

    public:
        // Create a Leaf whose val is c
        Tree(char c);

        // Create a tree from its two childrens
        Tree(Tree left, Tree right);

        // Get tree information
        void toString();
}

#endif 

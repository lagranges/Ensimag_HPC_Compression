#include "tree.hpp"


Tree::Tree(char c)
{
    this->left = NULL;
    this->right = NULL;
    this->val = c;
}

Tree::Tree(Tree *left, Tree *right)
{
    this->left = left;
    this->right = right;
}

Tree::Tree(Characters characters)
{
    priority_queue<Unit> pq = characters.get_frequencies();
    pq.pop();
    cout << pq.size() << endl;
    cout << characters.get_frequencies().size() << endl;
}

void Tree::display()
{
    if(this->left != NULL) 
        this->left->display();
    printf("\t %c", this->val);
    if(this->right != NULL) 
        this->right->display();
}


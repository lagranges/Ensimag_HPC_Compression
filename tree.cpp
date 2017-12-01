#include "tree.hpp"


Tree::Tree(node *u)
{
//     this->left = NULL;
//     this->right = NULL;
//     this->val = c;
    this->root = u;
}

// Tree::Tree(Tree *left, Tree *right)
// {
    // this->left = left;
    // this->right = right;
// }

Tree::Tree(Characters chars)
{
    priority_queue<node> pq = chars.get_frequencies();
    node *u,*u1,*u2;
    Tree *root_current;
    if(pq.size()==1){
        this->root = new node(pq.top());
    } else {
        while(pq.size()>=2){
            u1 = new node(pq.top());
            pq.pop();
            u2 = new node(pq.top());
            pq.pop();
            u = new node(NULL, u1->nb_occurs+u2->nb_occurs, u1, u2);
            pq.push(*u);
        }
        this->root = u;
    }
}

void Tree::display()
{
    cout << "Tree Display: " << endl;
    this->root->display();
    cout << endl;
}


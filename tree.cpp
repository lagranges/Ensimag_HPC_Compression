#include "tree.hpp"


Tree::Tree(node *u)
{
    this->root = u;
}

Tree::Tree(Characters chars)
{
    priority_queue<node> pq = chars.get_frequencies();
    node *u,*u1,*u2;
    if(pq.size()==1){
        u1 = new node(pq.top());
        u = new node('\0', u1->nb_occurs, u1, NULL);
        this->root = u;
    } else {
        while(pq.size()>=2){
            u1 = new node(pq.top());
            pq.pop();
            u2 = new node(pq.top());
            pq.pop();
            u = new node('\0', u1->nb_occurs+u2->nb_occurs, u1, u2);
            pq.push(*u);
        }
        this->root = u;
    }
}

void Tree::display()
{
    cout << "Tree Display (for a node [val, nb_occurence, depth, is_leaf]):  " << endl;
    this->root->display();
    cout << "\nEnd tree display"<<endl;    
}


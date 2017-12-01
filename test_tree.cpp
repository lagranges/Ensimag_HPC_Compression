#include <iostream>

#include "tree.hpp"

using namespace std;

int main(){
    // Test first constructor
    // Tree *t = new Tree('c');
    // Tree *t2 = new Tree('k');
    // Second constructor
    // Tree *t3 = new Tree(t,t2);
    // t->display();
    printf("\n");
    // t3->display();
    printf("\n");
    Characters chars = Characters("mini.txt");
    Tree *t4 = new Tree(chars);
    t4->display();
}
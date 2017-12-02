#include "dictionnary.hpp"

int main(){
    Characters chars = Characters("mini.txt");
    Tree *t4 = new Tree(chars);
    t4->display();
    Dictionnary dict = Dictionnary(*t4);
    dict.display();

}
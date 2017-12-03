#include "dictionnary.hpp"

int main(){
    Characters chars = Characters("mini.txt");
    Tree *t4 = new Tree(chars);
    t4->display();
    Dictionnary dict = Dictionnary(*t4);
    dict.display();

    //Concaite binary
    BinaryCode c1,c2,c3;
    c1.push_back(zero);
    c2.push_back(one);
    c2.push_back(one);
    c1 += c2;
    cout << "[TEST] Binary code Display:" << endl;
    c1.display();
    cout << "\n[TEST] End of binary code Display" << endl;
}
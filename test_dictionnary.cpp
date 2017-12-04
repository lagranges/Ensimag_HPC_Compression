#include "dictionnary.hpp"

int main(){
    Characters chars = Characters("aa.txt");
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
    c3 = BinaryCode('a');
    cout << (c2.get_first_char(*t4) == '\0') << endl;
    c1.display();
    cout << c1.get_first_char(*t4) << endl;
    c1.display();
    cout<<endl;
    cout << "[TEST] Binary code Display:" << endl;
    c1.display();
    cout << endl;
    c3.display();
    cout << "\n[TEST] End of binary code Display" << endl;
}
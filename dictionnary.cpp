#include "dictionnary.hpp"
#include <stack>

struct code{
    node nod;
    deque<BIT> cod;

    code (){}
    code(node n){
        nod = n;
    }

    code(node n, deque<BIT> c, bool left){
        nod = n;
        cod = c;
        if(left)
            cod.push_back(zero);
        else
            cod.push_back(one);
    }
};

Dictionnary::Dictionnary(Tree tree)
{
    node* root = tree.get_root();
    stack<code> explored_nodes;
    code c = code(*root);
    code top = code();
    explored_nodes.push(c);
    while(!explored_nodes.empty()){
        top = explored_nodes.top();
        if (!top.cod.empty())
            cout << top.cod.front() << "+"<< top.nod.nb_occurs << "  "  ;
        explored_nodes.pop();
        if(top.nod.is_leaf()){
            cout << top.cod.front() << "+"<< top.nod.nb_occurs << "  "  ;            
            dict[top.nod.val] = top.cod;
        }
        else{
            c = code(*top.nod.left, top.cod, true);
            explored_nodes.push(c);
            c = code(*top.nod.right, top.cod, false);
            explored_nodes.push(c);
        }
    }
    
};

void Dictionnary::display(){
    cout << "Dictionnary Display: \n \t Size: "<< dict.size()<< "\n\t";
    for(map<char, deque<BIT> >::iterator it=dict.begin();
        it!=dict.end(); ++it){
        cout << "    [" << it->first << ", ";
        deque<BIT> binary_code = it->second;
        while(!binary_code.empty()){
            BIT b = binary_code.front();
            cout << b <<"";
            binary_code.pop_front();
        }
        cout <<"]";
    }
    cout<<"\nEnd dictionnary display"<<endl;

};
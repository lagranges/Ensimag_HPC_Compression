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
        explored_nodes.pop();
        if(top.nod.is_leaf()){
            dict[top.nod.val] = BinaryCode(top.cod);
        }
        else{
            if(top.nod.left != NULL){
                c = code(*top.nod.left, top.cod, true);
                explored_nodes.push(c);
            }
            if(top.nod.right != NULL){
                c = code(*top.nod.right, top.cod, false);
                explored_nodes.push(c);
            }
        }
        
    }
    
};

void BinaryCode::display()
{
    deque<BIT> temp = list;
    while(!temp.empty()){
        BIT b = temp.front();
        cout << b;
        temp.pop_front();
    }
}

void Dictionnary::display()
{
    cout << "Dictionnary Display: \n \t Size: "<< dict.size()<< "\n\t";
    for(map<char, BinaryCode >::iterator it=dict.begin();
        it!=dict.end(); ++it){
        cout << "    [" << it->first << ", ";
        BinaryCode binary_code = it->second;
        binary_code.display();
        cout <<"]";
    }
    cout<<"\nEnd dictionnary display"<<endl;

};

void BinaryCode::operator+=(const BinaryCode& b)
{
    deque<BIT> temp = b.list;
    while(!temp.empty())
    {
        list.push_back(temp.front());
        temp.pop_front();
    }
}

bool BinaryCode::is_equal(BinaryCode const& b) const
{
    if(list.size()!=b.list.size()) return false;
    deque<BIT> temp1 = list, temp2 = b.list;
    while(!temp1.empty())
    {
        if(temp1.back()!=temp2.back()) return false;
        temp1.pop_back();
        temp2.pop_back();
    }
    return true;
}

bool operator==(BinaryCode const& a, BinaryCode const& b) 
{
    return a.is_equal(b);
}

char BinaryCode::get_one_byte(){
    int res=0;
    BIT b;
    for(int i=0;i<8;i++)
    {
        if(!list.empty()){
            b = list.front();
            list.pop_front();
        } else {
            b = zero;
        }
        // Just for testing -> removable
        res = 2*res + b;
    }
    return (char) res;
}

char Dictionnary::get_char(BinaryCode bc)
{
    char res = '\0';
    for(map<char,BinaryCode>::iterator it = dict.begin(); 
        it!=dict.end(); it++)
        {
            if(bc==it->second) res = it->first;
        }
    return res;
}

BinaryCode::BinaryCode(char c)
{
    int n = (int) c;
    for(int i=0;i<8;i++)
    {
        list.push_front(((n>>i)&1)?one:zero);
    }
}

char BinaryCode::get_first_char(Tree tree)
{
    deque<BIT> tmp = list;
    bool is_leaf = false;
    BIT current_bit;
    node* current_nod = tree.get_root();
    while(!tmp.empty() && !is_leaf){
        current_bit = tmp.front();
        tmp.pop_front();
        if(current_bit)
            current_nod = current_nod->right;
        else 
            current_nod = current_nod->left;
        if(current_nod == NULL) break;
        is_leaf = current_nod->is_leaf();       
    }
    if(is_leaf)
        list = tmp;
    return is_leaf?current_nod->val:'\0';
}

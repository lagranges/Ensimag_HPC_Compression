#include <iostream>
#include <queue>
#include "characters.hpp"
#include <fstream>

using namespace std;

int main(){
    Unit u;
    priority_queue <Unit> pq;
    u = Unit('a', 10);
    pq.push(u);
    u = Unit('b', 20);
    pq.push(u);
    u = Unit('c', 5);
    pq.push(u);

    cout <<"pq contains" << pq.size() << " elements \n";
    while(!pq.empty()){
        cout << pq.top().get_char() << endl;
        pq.pop();
    }

    Characters chars = Characters("mini.txt");
    chars.display();  
}
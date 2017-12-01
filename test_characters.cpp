#include <iostream>
#include <queue>
#include "characters.hpp"
#include <fstream>

using namespace std;

int main(){
    node u;
    priority_queue <node> pq;
    u = node('a', 10, NULL, NULL);
    pq.push(u);
    u = node('b', 20, NULL, NULL);
    pq.push(u);
    u = node('c', 5, NULL, NULL);
    pq.push(u);

    cout <<"pq contains" << pq.size() << " elements \n";
    while(!pq.empty()){
        cout << pq.top().val << endl;
        pq.pop();
    }

    Characters chars = Characters("mini.txt");
    chars.display();  
}
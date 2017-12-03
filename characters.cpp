#include "characters.hpp"

// display object information -> For testing 
void Characters::display()
{
    while(!pq.empty()){
        cout << pq.top().val << 
        "  " << pq.top().nb_occurs <<endl;
        pq.pop();
    }
}

// Read file and update the priority queue pq
Characters::Characters(string file_name)
{
    ifstream my_file;
    long frequencies[256] = {0};
    my_file.open(file_name);
    char ch;
    // TODO Problem with french character
    while(my_file.get(ch))
    {
        frequencies[(int)ch]++;
    }
    node u;
    for(int i=0; i<256;i++)
    {
        if(frequencies[i]>0){
            u = node(i,frequencies[i],NULL, NULL);
            pq.push(u);
        }
    }
}
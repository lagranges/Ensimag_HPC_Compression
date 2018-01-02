#include "characters.hpp"

// display object information -> For testing 
void Characters::display()
{
    priority_queue<node> pqt = pq; 
    while(!pqt.empty()){
        cout << pqt.top().val << 
        "  " << pqt.top().nb_occurs <<endl;
        pqt.pop();
    }
}

// Read file and update the priority queue pq
Characters::Characters(string file_name)
{
    ifstream my_file;
    long long int frequencies[256] = {0};
    my_file.open(file_name.c_str());
    char ch;
    nb_chars = 0;
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
            nb_chars += frequencies[i];
        }
    }
}

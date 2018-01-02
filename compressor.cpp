#include "compressor.hpp"

Compressor::Compressor(string f){
    file_name = f;
    chars = Characters(file_name);
    chars.display();
    Tree *t = new Tree(chars);
    dict = Dictionnary(*t);
    dict.display();
}

void Compressor::generate(string compressed_file_name)
{
    ifstream input_file;
    ofstream output_file;
    compressed_file = compressed_file_name; 
    input_file.open(file_name.c_str());
    output_file.open((compressed_file+".comp").c_str());
    BinaryCode binary_code ;
    // write the huffman information in the head of compressed file
    // It's suffient to save "chars" attribute
    int size_chars = chars.get_frequencies().size();
    priority_queue<node> pq = chars.get_frequencies();
    output_file << size_chars;
    output_file << "s";
    while(!pq.empty())
    {
        output_file << pq.top().nb_occurs << endl;
        output_file << pq.top().val;
        cout << " " << pq.top().nb_occurs << " " << pq.top().val << endl;
        pq.pop();
        output_file << " ";
    }
    char ch, ctemp;
    // write the number of chars
    output_file << chars.get_nb_chars();
    cout << chars.get_nb_chars() << endl;
    // encoding the characters
    while(input_file.get(ch))
    {
        binary_code += dict.get_binary_code(ch);
        while(binary_code.get_list().size()>=8){
            ctemp = binary_code.get_one_byte();
            output_file << ctemp;
        }
    }
    output_file << binary_code.get_one_byte();
    input_file.close(); 
    output_file.close();
}

long long int ignore_head(ifstream *out_file){
    int size_chars;
    char val;
    long long int nb_occurs;
    node nod;
    priority_queue<node> pq ;
    *out_file >> size_chars;
    *out_file >> val;
    for(int i=0; i < size_chars; i++)
    {
        *out_file >> nb_occurs;
        out_file->get(val);
        out_file->get(val);
        pq.push(nod);
    }
    *out_file >> nb_occurs;
    cout << nb_occurs << endl;
    return nb_occurs;
}
void Compressor::display()
{
    ifstream in_file, out_file;
    in_file.open(file_name.c_str());
    out_file.open((compressed_file+".comp").c_str());
    char ch;
    ignore_head(&out_file);
    cout << "Original text :\n";
    while(in_file.get(ch))
    {
        cout << ch;
    }    
    cout << endl;
    int n;
    cout << "Dictionnary" << endl;
    dict.display();
    cout << compressed_file << " display (in binary): " << endl;
    cout << "\tNumber of charaters :";
    long long int lg;
    out_file >> lg;
    cout<< lg <<endl;
    cout << "\tEncoded charaters :";
    while(out_file.get(ch))
    {
        n = (int) ch;
        for(int i=7; i>=0;i--){
            cout << ((n>>i)&1) ;
        }
    }
    cout << "\nEnd of Compressor display" << endl;
    in_file.close();
    out_file.close();
}

Decompressor::Decompressor(string f)
{
    compressed_file = f;
    ifstream input_file;
    input_file.open(compressed_file.c_str());
    int size_chars;
    char val;
    long long int nb_occurs;
    node nod;
    priority_queue<node> pq ;
    input_file >> size_chars;
    input_file >> val;
    for(int i=0; i < size_chars; i++)
    {
        input_file >> nb_occurs;
        input_file.get(val);
        input_file.get(val);
        cout << i << " " << nb_occurs << " " << val << endl;
        node nod = node(val, nb_occurs, NULL, NULL);
        pq.push(nod);
    }
    chars = Characters(pq);
    chars.display();
    tree = Tree(chars);
    dict = Dictionnary(tree);
    dict.display();
}

void Decompressor::generate(string decompressed_file)
{
    ifstream input_file;
    ofstream output_file;
    file_name = decompressed_file; 
    input_file.open(compressed_file.c_str());
    output_file.open((decompressed_file+".txt").c_str());
    // ignore header
    BinaryCode binary_code,bc_temp ;
    char ch, ctemp;
    // read the number of chars
    long long int nb_chars;
    //input_file >> nb_chars;
    nb_chars = ignore_head(&input_file);
    chars.set_nb_chars(nb_chars);
    long long int count_chars = 0;
    //cout << nb_chars << endl;
    // dencoding the characters
    while(input_file.get(ch) || count_chars < nb_chars )
    {
        bc_temp = BinaryCode(ch);
        binary_code += bc_temp;
        bool v_break;
        while(true){
            ctemp = binary_code.get_first_char(tree);
            if(ctemp == '\0' || count_chars == nb_chars)
                break;
            output_file << ctemp;
            count_chars ++;
        }
    }
    // output_file << binary_code.get_one_byte();
    // cout << endl;
    input_file.close(); 
    output_file.close();
}

void Decompressor::display(string decompressed_file)
{
    
}

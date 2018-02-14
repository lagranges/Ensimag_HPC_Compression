#include "compressor.hpp"
#include <ctime>
#include <omp.h>


Compressor::Compressor(string f){
    file_name = f;
    clock_t begin = clock();
    chars = Characters(file_name);
    //chars.display();
    Tree *t = new Tree(chars);
    dict = Dictionnary(*t);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Huffman contruction Time: " << elapsed_secs << endl;
    //dict.display();
}

void Compressor::generate(string compressed_file_name)
{
    ofstream output_file_t[N_THREAD];
    ifstream input_file_t[N_THREAD];
    ifstream input_file;
    ifstream input_filet;
    ofstream output_file;
    compressed_file = compressed_file_name; 
    input_file.open(file_name.c_str());
    output_file.open(compressed_file.c_str());
    for(int i=0; i < N_THREAD; i++){
        output_file_t[i].open(compressed_file.c_str());
        input_file_t[i].open(file_name.c_str());
    }
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
        //cout << " " << pq.top().nb_occurs << " " << pq.top().val << endl;
        pq.pop();
        output_file << " ";
    }
    char ch, ctemp;
    // write the number of chars
    // chunk information
    long long int milestones = output_file.tellp();
    long long int frequencies[256] = {0};
    clock_t begint = clock();
    input_filet.open(file_name.c_str());
    long long int chunk_nb_chars=0, chunk_nb_bytes =0, 
         milestone_chars = 0, milestone_bytes = milestones;
    int chunk_id = 0;
    while(input_filet.get(ch))
    {
        frequencies[(int) ch]++;
        chunk_nb_chars++;
        if(chunk_nb_chars == chars.get_nb_chars()/N_THREAD && chunk_id != N_THREAD-1) {
            for(int i=0; i<256; i++){
                if(frequencies[i]>0){
                    chunk_nb_bytes 
                        += frequencies[i]*dict.get_binary_code((char) i)
                        .get_list().size();
                }
                frequencies[i] = 0;
            }
            chunks[chunk_id] = new chunk(chunk_id, chunk_nb_chars, 
                    chunk_nb_bytes, milestone_chars, milestone_bytes);
            milestone_chars += chunk_nb_chars; 
            chunk_nb_chars = 0;
            chunk_id++;
            chunk_nb_bytes = 0;
        }
    }

    for(int i=0; i<256; i++){
        if(frequencies[i]>0){
            chunk_nb_bytes 
                += frequencies[i]*dict.get_binary_code((char) i).size();
        }
    }
    chunks[chunk_id] = new chunk(chunk_id, 
            chunk_nb_chars, chunk_nb_bytes, milestone_chars, milestone_bytes);   
   for(int i=0; i<N_THREAD; i++){
        output_file << chunks[i]->nb_chars;
        output_file << "s";
        output_file << chunks[i]->nb_bytes;
        output_file << "s";
    }

    output_file << chars.get_nb_chars();
    milestones = output_file.tellp();
    milestone_bytes = milestones;
    for(int i=0; i<N_THREAD; i++){
        chunks[i]->set_milestone_bytes(milestone_bytes);
        chunk_nb_bytes = chunks[i]->nb_bytes;
        milestone_bytes += (chunk_nb_bytes/8+2);   
    }

    clock_t endt = clock();
    double elapsed_secst = double(endt - begint) / CLOCKS_PER_SEC;
    cout << "Chunking time: " << elapsed_secst << endl;
    clock_t begin = clock();
    // encoding the characters
    output_file.seekp(milestones);
    for(int i=0; i < N_THREAD; i++){
        output_file_t[i].seekp(chunks[i]->milestone_bytes);
        input_file_t[i].seekg(chunks[i]->milestone_chars);
    }
    int id_thread;
    //while(input_file.get(ch))
    //{
    //    binary_code += dict.get_binary_code(ch);
    //    while(binary_code.get_list().size()>=8){
    //        ctemp = binary_code.get_one_byte();
    //        output_file << ctemp;
    //    }
    //}
    //chunk chunks[id_thread]-> *chunks[0];
    //dict.display();
    long long int count;
    #pragma omp parallel private(id_thread) private(ch) private(binary_code) private(ctemp) private(count) num_threads(N_THREAD)
    {
        count = 0;
        id_thread = omp_get_thread_num();
        while(count<chunks[id_thread]->nb_chars){
           input_file_t[id_thread].get(ch);
           count++;
           binary_code += dict.get_binary_code(ch);
           chunks[id_thread]->i_chars++;

           while(binary_code.size()>=8){
                ctemp = binary_code.get_one_byte();
                output_file_t[id_thread] << ctemp;
           }
        }
           ctemp = binary_code.get_one_byte();
           output_file_t[id_thread] << ctemp;
    }
    //for(int i=0;i<N_THREAD;i++){
    //    chunks[i]->display();
    //}
    output_file_t[N_THREAD-1] << "x";
    for(int i=0; i<N_THREAD; i++){
        output_file_t[N_THREAD-1] << chunks[i]->milestone_chars;
        output_file_t[N_THREAD-1] << "s";
        output_file_t[N_THREAD-1] << chunks[i]->milestone_bytes;
        output_file_t[N_THREAD-1] << "s";
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Encoding time: " << elapsed_secs << endl;
    input_file.close(); 
    for(int i=0; i < N_THREAD; i++){
        output_file_t[i].close();
        input_file_t[i].close();
    }
    output_file.close();
    //cout << "ok" << endl;
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
    for(int i=0; i<N_THREAD; i++){
        *out_file >> nb_occurs;
        *out_file >> val;
        *out_file >> nb_occurs;
        *out_file >> val;
    }
    *out_file >> nb_occurs;
    //cout << "nb chars: " << nb_occurs << endl;
    return nb_occurs;
}

void Compressor::display()
{
    ifstream in_file, out_file;
    in_file.open(file_name.c_str());
    out_file.open(compressed_file.c_str());
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
        //cout << i << " " << nb_occurs << " " << val << endl;
        node nod = node(val, nb_occurs, NULL, NULL);
        pq.push(nod);
    }
    long long int nb_chars, nb_bytes; 
    for(int i=0; i < N_THREAD; i++)
    {
        input_file >> nb_chars;
        input_file.get(val);
        input_file >> nb_bytes;
        input_file.get(val);
        chunks[i] = new chunk(i, nb_chars, 
                    nb_bytes, 0, 0);
    } 
    
    chars = Characters(pq);
    //chars.display();
    tree = Tree(chars);
    //tree.display();
    dict = Dictionnary(tree);
    //dict.display();
}

void Decompressor::generate(string decompressed_file)
{
    ofstream output_file_t[N_THREAD];
    ifstream input_file_t[N_THREAD];
    ifstream input_file, input_file_temp;
    ofstream output_file;
    file_name = decompressed_file; 
    input_file.open(compressed_file.c_str());
    input_file_temp.open(compressed_file.c_str());
    output_file.open(decompressed_file.c_str());
    for(int i=0; i < N_THREAD; i++){
        input_file_t[i].open(compressed_file.c_str());
        output_file_t[i].open(decompressed_file.c_str());
    }
    // ignore header
    BinaryCode binary_code,bc_temp ;
    char ch, ctemp;
    // read the number of chars
    long long int nb_chars;
    //input_file >> nb_chars;
    nb_chars = ignore_head(&input_file);
    chars.set_nb_chars(nb_chars);
    long long int count_chars = 0;
    // dencoding the characters
    clock_t begin = clock();
    long long int chunk_nb_bytes,milestones = input_file.tellg();
    long long int milestone_bytes =milestones, milestone_chars =0;
    // read the last line
    // find the position of last line
    input_file_temp.seekg(0, input_file_temp.end); 
    long long int pos_last_line = input_file_temp.tellg();
    char ch_ll;
    while(ch_ll!='x'){
        pos_last_line--;
        input_file_temp.seekg(pos_last_line);
        input_file_temp >> ch_ll;
    }
    long long int milestone_temp;
    char val;
    for(int i=0; i<N_THREAD; i++){
        input_file_temp >> milestone_temp;
        input_file_temp >> val;
        chunks[i]->set_milestone_chars(milestone_temp);
        input_file_temp >> milestone_temp;
        input_file_temp >> val;
        chunks[i]->set_milestone_bytes(milestone_temp);
    }
    for(int i=0; i < N_THREAD; i++){
        output_file_t[i].seekp(chunks[i]->milestone_chars);
        input_file_t[i].seekg(chunks[i]->milestone_bytes);
    }
    
    //for(int i=0;i<N_THREAD;i++){
    //    chunks[i]->display();
    //}
    /*
    while(input_file.get(ch) || count_chars < nb_chars )
    {
        bc_temp = BinaryCode(ch);
        binary_code += bc_temp;
        while(true){
            ctemp = binary_code.get_first_char(tree);
            if(ctemp == '\0' || count_chars == nb_chars)
                break;
            output_file << ctemp;
            count_chars ++;
        }
    } */
    int id_thread;
    //dict.display();
    long long int count;
#pragma omp parallel private(id_thread) private(bc_temp) private(binary_code) private(ctemp) private(ch) private(count) num_threads(N_THREAD)
    {
        id_thread = omp_get_thread_num();
        count = 0;
        while(count < chunks[id_thread]->nb_chars){
            input_file_t[id_thread].get(ch);
            bc_temp = BinaryCode(ch);
            binary_code += bc_temp;
            while(true){
                ctemp = binary_code.get_first_char(tree);
                if(ctemp == '\0' || count == chunks[id_thread]->nb_chars)
                    break;
                output_file_t[id_thread] << ctemp;
                count++;
                }
            }
        
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Decoding Time: " << elapsed_secs << endl;
    for(int i=0; i < N_THREAD; i++){
        output_file_t[i].close();
        input_file_t[i].close();
    }
    input_file.close(); 
    output_file.close();
}

void Decompressor::display(string decompressed_file)
{
    
}

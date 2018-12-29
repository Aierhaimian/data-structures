//
// Created by scu_d on 2017/11/17.
//
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
#include "huffman_code.h"

// 选择最小和次小的两个结点，建立哈夫曼树调用
void huffman_code::select(HufNode *huf_tree, unsigned int n, int &s1, int &s2){
    unsigned long min = ULONG_MAX;

    //find the minimum node
    for (int i = 0; i < n; ++i) {
        if (huf_tree[i].parent == 0 && huf_tree[i].weight <min){
            min = huf_tree[i].weight;
            s1 = i;
        }
    }
    huf_tree[s1].parent = 1;// Ok, it's the minimum node now.

    //find the second minimum node
    min = ULONG_MAX;
    for (int i = 0; i < n; ++i) {
        if (huf_tree[i].parent == 0 && huf_tree[i].weight < min){
            min = huf_tree[i].weight;
            s2 = i;
        }
    }
}
// 建立哈夫曼树
void huffman_code::CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num){
    int s1, s2;
    for (int i = char_kinds; i < node_num; ++i) {
        select(huf_tree, i, s1, s2);//选择最小的两个结点
        huf_tree[s1].parent = i;
        huf_tree[s2].parent = i;
        huf_tree[i].lchild = s1;
        huf_tree[i].rchild = s2;
        huf_tree[i].weight = huf_tree[s1].weight + huf_tree[s2].weight;
    }
}
// 生成哈夫曼编码
void huffman_code::HufCode(HufNode *huf_tree, unsigned char_kinds){
    int cur, next, index;
    char *code_tmp;
    code_tmp = new char[256];//Temporary code, up to 256 leaves, coding length does not exceed 255
    code_tmp[256-1] = '\0';

    for (int i = 0; i < char_kinds; ++i) {
        index = 256 - 1;//Encoding temporary space index initialization

        //Reverse traversal from leaf to root for encoding
        for (cur = i, next = huf_tree[i].parent; next != 0; cur = next, next = huf_tree[next].parent) {
            if (huf_tree[next].lchild == cur)
                code_tmp[--index] = '0';//left '0'
            else
                code_tmp[--index] = '1';//right '1
        }
        huf_tree[i].code = new char[256-index];//The i_th character encoding dynamic allocation of memory space
        strcpy(huf_tree[i].code, &code_tmp[index]);//Forward save encoding to the corresponding node in the tree
    }
    delete [] code_tmp;
}


// 压缩函数
int huffman_code::compress(std::string file_name, std::string out_filename){
    unsigned int char_kinds;// 字符种类
    unsigned long file_len = 0;
    unsigned char char_temp;// 暂存8bits字符
    TmpNode node_temp;
    unsigned int node_num;
    HufTree huf_tree;
    char code_buf[256] = "\0";// 待存编码缓冲区
    unsigned int code_len;

    //Dynamically allocate 256 nodes, temporary storage character frequency,
    // statistics and copied to the tree node immediately after the release
    TmpNode *tmp_nodes = new TmpNode[256];

    //Init temporary node
    for (int i = 0; i < 256; ++i) {
        tmp_nodes[i].weight = 0;
        tmp_nodes[i].uch = i;//The 256 subscripts of the array correspond to 256 characters
    }

    //Traverse the file, get the character frequency
    std::ifstream in_file(file_name, std::ios::in|std::ios::binary);
    if(!in_file){
        return -1;
    }
    in_file.read((char *)&char_temp, sizeof(unsigned char));
    while (!in_file.eof()){
        ++tmp_nodes[char_temp].weight;
        ++file_len;
        in_file.read((char *)&char_temp, sizeof(unsigned char));
    }

    in_file.close();

    //Sort, the frequency of zero put last, remove
    for (int i = 0; i < 256-1; ++i) {
        for (int j = i + 1; j < 256; ++j) {
            if (tmp_nodes[i].weight < tmp_nodes[j].weight) {
                node_temp = tmp_nodes[i];
                tmp_nodes[i] = tmp_nodes[j];
                tmp_nodes[j] = node_temp;
            }
        }
    }

    //Statistics of the actual character types (the number of occurrences is not 0)
    for (unsigned int i = 0; i < 256; ++i) {
        if(tmp_nodes[i].weight == 0){
            char_kinds = i;
            break;
        }
    }

    std::cout<<"writing compressed file..."<<std::endl;
    if (char_kinds == 1){
        std::cout<<"char_kinds == 1"<<std::endl;
        std::ofstream out_file(out_filename);
        out_file.write((char *)&char_kinds, sizeof(unsigned int));
        out_file.write((char *)&tmp_nodes[0].uch, sizeof(unsigned char));
        out_file.write((char *)&tmp_nodes[0].weight, sizeof(unsigned long));
        delete[] tmp_nodes;
        out_file.close();
    }
    else{
        //According to the number of characters, calculate the number of nodes needed to establish Huffman tree
        node_num = 2 * char_kinds -1;
        //Dynamically establish the necessary nodes of the Huffman tree
        huf_tree = new HufNode[node_num];

        //init the 0 to char_kinds-1 nodes
        for (int i = 0; i < char_kinds; ++i) {
            //Copy the characters and frequency of the temporary node to the tree node
            huf_tree[i].uch = tmp_nodes[i].uch;
            huf_tree[i].weight = tmp_nodes[i].weight;
            huf_tree[i].parent = 0;
        }
        delete[] tmp_nodes;

        //init the char_kinds to node_num nodes
        for (int i = char_kinds; i < node_num; ++i) {
            huf_tree[i].parent = 0;
        }

        //Create the Huffman Tree
        huffman_code::CreateTree(huf_tree, char_kinds, node_num);

        //Create the Huffman Encode
        huffman_code::HufCode(huf_tree,char_kinds);

        //write char and weight, for extract process to rebuild Huffman Tree
        std::ofstream out_file(out_filename);
        out_file.write((char *)&char_kinds, sizeof(unsigned int));
        for (int i = 0; i < char_kinds; ++i) {
            out_file.write((char *)&huf_tree[i].uch, sizeof(unsigned char));
            out_file.write((char *)&huf_tree[i].weight, sizeof(unsigned long));
        }

        //write file length and weight information
        out_file.write((char *)&file_len, sizeof(unsigned long));

        std::ifstream in_file(file_name, std::ios::in|std::ios::binary);
        if(!in_file){
            return -1;
        }
        in_file.read((char *)&char_temp, sizeof(unsigned char));
        while (!in_file.eof()){
            //匹配字符对应编码
            for (int i = 0; i < char_kinds; ++i) {
                if (char_temp == huf_tree[i].uch){
                    strcat(code_buf, huf_tree[i].code);
                }
            }
            //以8位（1Byte）为处理单元
            while (strlen(code_buf) >= 8){
                char_temp = '\0';//清空字符暂存空间，改为暂存字符对应编码
                for (int k = 0; k < 8; ++k) {
                    char_temp <<= 1;//左移一位，为下一个bit腾出位置
                    if (code_buf[k] == '1')
                        char_temp |= 1;//当编码为"1"，通过或操作符将其添加到字节的最低位
                }
                out_file.write((char *)&char_temp, sizeof(unsigned char));// 将字节对应编码存入文件
                strcpy(code_buf, code_buf+8);//编码缓存去除已处理的前八位
            }
            in_file.read((char *)&char_temp, sizeof(unsigned char));
        }

        //处理最后不足8bits编码
        code_len = strlen(code_buf);
        if(code_len > 0){
            char_temp = '\0';
            for (int i = 0; i < code_len; ++i) {
                if(code_buf[i] == '1'){
                    char_temp |= 1;
                }
            }
            char_temp <<=8-code_len;
            out_file.write((char *)&char_temp, sizeof(unsigned char));
        }

        in_file.close();
        out_file.close();

        delete [] huf_tree;
    }

    double rsize_d,dsize_d;
    std::ifstream rfile(file_name);
    if(!rfile.is_open()) return -1;

    rfile.seekg(0,std::ios_base::end);
    std::streampos rsize = rfile.tellg();
    rfile.close();

    std::ifstream dfile(out_filename);
    if(!dfile.is_open()) return -1;

    dfile.seekg(0,std::ios_base::end);
    std::streampos dsize = dfile.tellg();
    dfile.close();

    rsize_d = rsize;
    dsize_d = dsize;
    std::cout<<"The "<<file_name<<" is: "<<rsize/1024<<" KB."<<std::endl;
    std::cout<<"The compressed file "<<out_filename<<" is: "<<dsize/1024<<" KB."<<std::endl;
    std::cout<<"The compression ratio is: "<<(rsize_d - dsize_d)/rsize_d *100<<"%"<<std::endl;

    return 1;
}//compress


// 解压函数
int huffman_code::extract(std::string file_name, std::string out_filename){
    unsigned long writen_len = 0;// 控制文件写入长度
    unsigned long file_len;
    unsigned int char_kinds;
    unsigned int node_num;
    HufTree huf_tree;
    unsigned char code_temp;
    unsigned int root;// 保存根节点索引，供匹配编码使用

    std::ifstream in_file(file_name, std::ios::in|std::ios::binary);
    if(!in_file){
        return -1;
    }
    in_file.read((char *)&char_kinds, sizeof(unsigned int));

    if (char_kinds == 1){
        in_file.read((char *)&code_temp, sizeof(unsigned char));
        in_file.read((char *)&file_len, sizeof(unsigned long));

        std::ofstream out_file(out_filename);
        while (file_len--){
            out_file.write((char *)&code_temp, sizeof(unsigned char));
        }

        in_file.close();
        out_file.close();

    }else{
        node_num = 2*char_kinds - 1;
        huf_tree = new HufNode[node_num];

        //读取字符及对应权重，存入哈夫曼树结点
        //buffer[1]~buffer[152]
        for (int i = 0; i < char_kinds; ++i) {
            in_file.read((char *)&huf_tree[i].uch, sizeof(unsigned char));
            in_file.read((char *)&huf_tree[i].weight, sizeof(unsigned long));
            huf_tree[i].parent = 0;
        }

        //初始化后node_num-char_kins个结点的parent
        for (int i = char_kinds; i < node_num; ++i) {
            huf_tree[i].parent = 0;
        }

        //重建哈夫曼树
        huffman_code::CreateTree(huf_tree, char_kinds, node_num);

        //读完字符和权重信息，紧接着读取文件长度和编码，进行解码
        in_file.read((char *)&file_len, sizeof(unsigned long));

        std::ofstream out_file(out_filename);
        root = node_num-1;
        int cnt = 154;
        while(1) {
            in_file.read((char *)&code_temp, sizeof(unsigned char));

            for (int i = 0; i < 8; ++i) {
                if (code_temp & 128)
                    root = huf_tree[root].rchild;
                else
                    root = huf_tree[root].lchild;

                if (root < char_kinds){
                    out_file.write((char *)&huf_tree[root].uch, sizeof(unsigned char));
                    ++writen_len;
                    if (writen_len == file_len)
                        break;
                    root = node_num - 1;
                }
                code_temp <<= 1;
            }
            if (writen_len == file_len)
                break;
            ++cnt;
        }
        in_file.close();
        out_file.close();

        delete [] huf_tree;
    }
    return 1;
}//extract

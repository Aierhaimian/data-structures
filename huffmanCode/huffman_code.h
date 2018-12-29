//
// Created by scu_d on 2017/11/17.
//

#ifndef HUFFMAN_CODE_HUFFMAN_CODA_H
#define HUFFMAN_CODE_HUFFMAN_CODA_H


class huffman_code {
private:
// 哈夫曼树结点
    typedef struct {
        unsigned char uch;				// 以8bits为单元的无符号字符
        unsigned long weight;			// 每类（以二进制编码区分）字符出现频度
        char *code;						// 字符对应的哈夫曼编码（动态分配存储空间）
        int parent, lchild, rchild;		// 定义双亲和左右孩子
    } HufNode, *HufTree;

    // 统计字符频度的临时结点
    typedef struct {
        unsigned char uch;			// 以8bits为单元的无符号字符
        unsigned long weight;		// 每类（以二进制编码区分）字符出现频度
    } TmpNode;
public:
    // 选择最小和次小的两个结点，建立哈夫曼树调用
    void select(HufNode *huf_tree, unsigned int n, int &s1, int &s2);
    // 建立哈夫曼树
    void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num);
    // 生成哈夫曼编码
    void HufCode(HufNode *huf_tree, unsigned char_kinds);

    // 压缩函数
    int compress(std::string file_name, std::string out_filename);
    // 解压函数
   int extract(std::string file_name, std::string out_filename);

};


#endif //HUFFMAN_CODE_HUFFMAN_CODA_H

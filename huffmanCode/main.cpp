#include <iostream>
#include <unistd.h>
#include <fstream>
#include <Windows.h>
#include "huffman_code.h"

using namespace std;

string file_name;
string command;

/*
 *  Input parameters:
 *      - r <Input file>
 *      - o <compress or decompress>
 *  Example:
 *      huffman_code.exe    -r xxx.txt -o compress
 *  Output:
 *      The compressed file
 *      Execution time
 * */

void option_input(int argc, char ** argv){
    int flag = 1;//1:correct argument 0：argument of help -1: error input format
    if (argc == 2){
        if ('h' == getopt(argc, argv, ":h")){
            cout<<"Description:"<<endl<<
                  "\tThe file compress and decompress program by using Huffman code Algorithm."<<endl<<endl<<
                  "Input parameters:"<<endl<<
                  "\t- r <Input file>"<<endl<<
                  "\t- o <compress or decompress>"<<endl<<endl<<
                  "Example:"<<endl<<
                  "\thuffman_code.exe    -r xxx.txt -o compress"<<endl<<endl<<
                  "Output"<<endl<<
                  "\tThe compressed file"<<endl<<
                  "\tExecution time"<<endl<<endl<<
                  "Author:"<<endl<<
                  "\t杜泽旭 2017E8013261181"<<endl<<endl<<
                  "Version:"<<endl<<
                  "\tV1.0.0"<<endl;
            flag = 0;
        }
        else{
            flag = -1;
        }
    }
    else if (argc == 5){
        int oc;//option character
        while ((oc = getopt(argc, argv, ":r:o:")) != -1){
            switch (oc){
                case 'r':
                {
                    file_name = optarg;
                    ifstream in_file(file_name,ios::in|ios::binary|ios::ate);
                    if (!in_file){
                        cerr<<"Input file does not exist."<<endl;
                        flag = -1;
                    }
                    in_file.close();
                }
                    break;
                case 'o':
                {
                    command = optarg;
                    if (command.compare("compress") != 0 && command.compare("decompress") != 0){
                        cerr<<"The command must be \"compress\" or \"decompress\"."<<endl;
                        flag = -1;
                    }
                }
                    break;
            }
        }
    }
    else{
        cout<<"require more arguments."<<endl;
        flag = -1;
    }

    if(flag <= 0){
        if(flag == -1){
            cout<<"Input -h to get more help and information."<<endl;
        }
        exit(-1);
    }

    cout<<"Processing, please wait.."<<endl;
}


int main(int argc, char ** argv) {
    DWORD comp_start_time, comp_end_time;
    DWORD ext_start_time, ext_end_time;
    int flag = 0;
    string compress_filename;
    string extract_filename;

    huffman_code hfop;

    option_input(argc, argv);//Deal with argument

    if (command.compare("compress") == 0) {
        for (int i = 0; i < file_name.size()-1; ++i) {
            if (file_name[i] == '.'){
                compress_filename = file_name.substr(0,i);
                break;
            }
        }
        compress_filename.append("_compressed.txt");

        comp_start_time = GetTickCount();
        flag = hfop.compress(file_name, compress_filename);
        comp_end_time = GetTickCount();
        cout<<"The compress file time is: "<<(comp_end_time - comp_start_time)<<"ms"<<endl;
    }
    else if(command.compare("decompress") == 0){
        for (int i = 0; i < file_name.size()-1; ++i) {
            if (file_name[i] == '.'){
                extract_filename = file_name.substr(0,i);
                break;
            }
        }
        extract_filename.append("_extracted.txt");

        ext_start_time = GetTickCount();
        flag = hfop.extract(file_name, extract_filename);
        ext_end_time = GetTickCount();
        cout<<"The decompress file time is: "<<(ext_end_time - ext_start_time)<<"ms"<<endl;
    }
    else{
        flag = -1;
    }


    if (flag == -1){
        cout<<"Sorry, there are some error occurs."<<endl;
        exit(-1);
    }
    else{
        cout<<"Operation is done!"<<endl;
    }
    return 0;
}
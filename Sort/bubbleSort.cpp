#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> bubbleSort(vector<int> &vec)
{
   for (int i=0; i<vec.size(); i++)
   {
        for (int j=0; j<vec.size()-i-1; j++)
        {
            if (vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
        }
   }

   return vec;
}

int main(int argc, char **argv)
{
    ifstream input(argv[1]); //打开待排序数据文件
    ofstream output(argv[2]); //打开已排序数据文件

    int numSize;
    input >> numSize;
    if (numSize <= 0)
    {
        cerr << "The numbers size error!" << endl;
        return -1;
    }

    vector<int> vec;
    int tmp;
    while(input >> tmp)
    {
        vec.push_back(tmp);
    }

    output << "The unsort number is: "<< endl;
    for(int i=0; i<vec.size(); i++)
    {
        output << vec[i] << " ";
    }
    output << endl;

    vector<int> res; 
    
    res = bubbleSort(vec);

    output << "The sorted number is: "<< endl;
    for(int i=0; i<res.size(); i++)
    {
        output << res[i] << " ";
    }
    output << endl;

    return 0;
}

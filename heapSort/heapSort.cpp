/******************************************************************
 *
 *      问题：堆排序
 *      作者：杜泽旭
 *      时间：2017.06.06
 *
 * ***************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<sys/time.h>
#include<stdlib.h>

using namespace std;


class Heap{
private:
    int *arrayHeap;
    int heapSize;
public:
    Heap(int size);
    void readArray(string filename);//读待排序数组文件
    void showArray();//打印数组
    void maxHeapLife(int i,int size);//调整最大堆
    void buildMaxHeap();//建立最大堆
    void heapSort();//堆排序算法
    ~Heap();
};

Heap::Heap(int size)
{
    heapSize = size;
    arrayHeap = new int[heapSize];
}

void Heap::readArray(string filename)
{
    ifstream ifs(filename.c_str(),ios::in);
    if(!ifs)
    {
        cout<<"open error!"<<endl;
    }
    string line;
    getline(ifs,line);
    istringstream istr(line);
    int tmp = 0;
    istr>>tmp;
    heapSize = tmp;
    for(int i=1;i<=tmp;i++)
        istr>>arrayHeap[i];
    ifs.close();
}

void Heap::showArray()
{
    cout<<"数组规模："<<heapSize<<endl;
    cout<<"数组元素："<<endl;
    for(int i=1;i<=heapSize;i++)
        cout<<arrayHeap[i]<<" ";
    cout<<endl;
}

void Heap::maxHeapLife(int i,int size)
{
    int lchild = 2*i;//i的左孩子节点序号
    int rchild = 2*i+1;//i的右孩子节点序号
    int max = i;//临时变量

    if(i<=size/2)//如果i不是叶节点就不用进行调整
    {
        if(lchild<=size && arrayHeap[lchild] > arrayHeap[max])
        {
            max = lchild;
        }
        if(rchild<=size && arrayHeap[rchild] > arrayHeap[max])
        {
            max = rchild;
        }
        if(max != i)
        {
            int tmp = 0;
            tmp = arrayHeap[i];
            arrayHeap[i] = arrayHeap[max];
            arrayHeap[max] = tmp;

            maxHeapLife(max,size);//递归调用
        }
    }
}

void Heap::buildMaxHeap()
{
    for(int i=heapSize/2;i>=1;i--)
    {
        maxHeapLife(i,heapSize);
    }
}

void Heap::heapSort()
{
    int i;

    buildMaxHeap();

    for(i=heapSize;i>=2;i--)
    {
        int tmp = 0;
        tmp =  arrayHeap[1];
        arrayHeap[1] = arrayHeap[i];
        arrayHeap[i] = tmp;

        maxHeapLife(1,i-1);

    }
}

Heap::~Heap()
{
    delete []arrayHeap;
}

int main(void)
{
    float time_use = 0;
    struct timeval start;
    struct timeval end;
    Heap h(1000000);
    h.readArray("array.txt");
    h.showArray();

    gettimeofday(&start,NULL);
    h.heapSort();
    gettimeofday(&end,NULL);

    h.showArray();

    time_use = ((end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec));//微秒

    cout<<"堆排序算法执行时间为："<<time_use<<"微秒"<<endl;

    return 0;
}

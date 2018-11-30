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
    int *arrayHeap; // 使用数组存储堆
    int heapSize;   // 堆可以存储最大元素个数
    int countSize;  // 堆中已经存储的元素个数

    void swap(int *array, int i, int j);    // 交换数组中i，j元素的位置
    void heapfiy(int *array, int n, int i); // 堆化
    
public:
    Heap(int size);
    void readArray(string filename);//读待排序数组文件
    void showArray();//打印数组
    void insert(int item); // 插入元素
    void removeMax(); // 删除堆顶元素
    void maxHeapLife(int i,int size);//调整最大堆
    void buildMaxHeap();//建立最大堆
    void heapSort();//堆排序算法
    ~Heap();
};

Heap::Heap(int size)
{
    arrayHeap = new int[size + 1];
    heapSize  = size;
    countSize = 0;
}

void Heap::swap(int *array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
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
    countSize = tmp;
    for(int i=1;i<=tmp;i++)
        istr>>arrayHeap[i];
    ifs.close();
}

void Heap::showArray()
{
    cout<<"堆中存储元素个数："<<countSize<<endl;
    cout<<"堆中存储的元素："<<endl;
    for(int i=1;i<=countSize;i++)
        cout<<arrayHeap[i]<<" ";
    cout<<endl;
}

void Heap::insert(int item)
{
    if(countSize >= heapSize)
        return; // 堆满返回
    countSize++;
    arrayHeap[countSize] = item;

    int i = countSize;
    while(i/2 > 0 && arrayHeap[i] > arrayHeap[i/2]) //从下往上
    {
        swap(arrayHeap, i, i/2);
        i = i/2;
    }
}

void Heap::heapfiy(int *array, int n, int i) //从上往下
{
    while(true)
    {
        int maxPos = i;
        if(i*2 <= n && array[i*2] > array[i]) maxPos = i*2;
        if(i*2+1 <=n && array[i*2+1] > array[maxPos]) maxPos = i*2+1;
        if(maxPos == i) return;

        swap(array, i, maxPos);

        i = maxPos;
    }
}

void Heap::removeMax()
{
    if(countSize <= 0)
        return; // 堆空返回

    arrayHeap[1] = arrayHeap[countSize];
    countSize--;

    heapfiy(arrayHeap, countSize, 1);

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
    for(int i=countSize/2;i>=1;i--)
    {
        //maxHeapLife(i,heapSize);
        heapfiy(arrayHeap, countSize, i);
    }
}

void Heap::heapSort()
{
    int i;

    buildMaxHeap(); // 建堆，时间复杂度：O(n)

    for(i=countSize;i>=2;i--) // 排序，时间复杂度：O(nlogn)
    {

        swap(arrayHeap, 1, i);
        // int tmp = 0;
        // tmp =  arrayHeap[1];
        // arrayHeap[1] = arrayHeap[i];
        // arrayHeap[i] = tmp;

        // maxHeapLife(1,i-1);
        heapfiy(arrayHeap, i-1, 1);
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

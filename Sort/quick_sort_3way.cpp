#include<iostream>
#include<cstdlib>
#include<ctime>
#define M 20
 
using namespace std;
static int count_insert = 0;
static int count_partion = 0;
 
struct index
{
 	  int left;
 	  int right;
};
 
// 其实使用标准库的swap函数就好，没必要自己实现
void swap(int& small, int& big)
{
	int temp = small;
	small = big;
	big = temp;
}
/*
|简述下插入排序：
|
|cur = left -> right 之间的数为待排序部分，pre代表已排序部分。
|
|先把当先位置元素arr[cur]存入tmp，然后比较arr[pre]和arr[cur]，
|如果待排序部分arr[cur] < arr[pre],则arr[pre + 1] = arr[pre]
|移位的目的是把较小的元素，这里是arr[cur]放入到已排序部分适当的位置
|这样每次arr[cur]都会被arr[pre]所覆盖，这也就是为什么刚开始tmp = arr[cur]的原因
|然后把tmp放置到arr[pre]位置处
*/
/*
void insert_sort( int arr[], int left, int right)
{
	int tmp, cur , pre;
	for (cur = left+1; cur < right; cur++)
	{
		pre = cur - 1;
		tmp = arr[cur];
 
		while ( tmp < arr[pre] && pre >= 0)
		{
			arr[pre + 1] = arr[pre];
			pre--;
		}
		arr[pre] = tmp;
	}
	count_insert += 1;
}*/

// 插入排序
void insert_sort(int arr[], int left, int right)
{
    if (right - left <= 1)
        return;

    for (int i=left+1; i<=right; ++i) // 未排序区间
    {
        int tmp = arr[i];
        int j;
        for (j=i-1; j>=left; --j) // 已排序区间
        {
            if (arr[j] > tmp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = tmp;
    }
}
/*
|简述下算法思路：
|当出现大量重复元素时，显然可以加以控制，改进效率。
|
|在划分循环中，每当扫描指针(i, j)停止时，交换i,j处的元素；
|同时判断指针处元素是否等于划分元素base；
|如果arr[i]等于划分元素，则把arr[i]和数组左边的元素交换；
|如果arr[j]等于划分元素，则把arr[j]和数组右边的元素。
|
|最后把两端的和划分元素相等的区域，移到数组中间来。
*/

//  -----------------------------------------------
//  |   =  |    <    |     ?     |  >   |    =    | 
//  -----------------------------------------------
//  ^      ^         ^           ^      ^         ^
//  |      |         |           |      |         |
// left   pleft      i           j    pright    right
struct index partion(int arr[], int left, int right)
{
	int i , j;
	int pleft, pright;
	int base;
	struct index p;
	
	if ( left > right ) exit(-1) ;
	
	i = left - 1, j = right;
 	pleft = left - 1, pright = right;
 	base = arr[right]; // 分区点
	//@_1 
	for (;;)
	{
	    while ( i < j && arr[ ++i ] < base );
	    	  
	    while ( i < j && arr[ --j ] > base ) if ( j <= left ) break;
  	  	  
  	  	if ( j == i ) break;
  	  	  
  	  	swap( arr[j] , arr[i]); // @_2
 
		if ( arr[i] == base )
  	  	 {
   	 		pleft += 1;
			swap(arr[i], arr[pleft]);   	 	  
         }
              
         if ( arr[j] == base )
         {
 	  		pright -= 1;
 	  	    swap( arr[j], arr[pright]);//@_3
		 }
	}//for
	 
	swap( arr[right], arr[i]); //@_4
	
	j = i - 1; i = i + 1;
	
    int tag;
	for (tag = left; tag <= pleft; tag++, j--) swap(arr[tag], arr[j]);
	
	for (tag = right - 1 ; tag >= pright; tag--, i++) swap(arr[tag], arr[i]);//@_5
	
	p.left = j, p.right = i ;
 
	count_partion += 1;
	
	return p;  
}
 
/*
| 如果划分后子数组的长度小于20，则用插入排序，
|否则快速排序。
|在经过N次递归划分后，会产生大量的比如长度为arr[0 -> 10]这样的小数组
|此时继续快速排序显然得不偿失。
*/

//  -----------------------------------------------
//  |       <       |   =   |           >         |
//  -----------------------------------------------
//  ^              ^         ^                    ^
//  |              |         |                    |
//  left    insert.left insert.right            right
void quick_sort(int arr[], int left, int right)
{
	if ( left < right )
	{
		if ( (right - left) <= M ) // M == 20
			insert_sort(arr, left, right);
		else
		{
			struct index sec = partion(arr, left, right);
			quick_sort(arr, left, sec.left);
			quick_sort(arr, sec.right, right);
		}
	}
}
 
int main()
{
	
	const int size = 500;
	static int s[size];
	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < size; i++)
		s[i] = rand()%100;
 
	quick_sort(s, 0, size-1);
 
	for (int i = 0; i < size; i++)
		cout << s[i] << " ";
	cout << endl;
	cout << "call insert_sort  " << count_insert << " times" <<endl;
	cout << "call partion_sort  " << count_partion << " times" <<endl;
 
	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int begin, int end)
{
    int pivot = vec[end];
    int i = begin;
    for (int j=begin; j<end; j++)
    {
        if (vec[j] < pivot)
        {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[end]);
    return i;
}

void quickSortSub(vector<int> &vec, int begin, int end)
{
    if (begin >= end)
        return;

    int p = partition(vec, begin, end);

    quickSortSub(vec, begin, p-1);
    quickSortSub(vec, p+1, end);

}

vector<int> quickSort(vector<int> &vec)
{
    int begin = 0;
    int end = vec.size()-1;
    quickSortSub(vec, begin, end);

    return vec;
}

int main(int argc, char **argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	int numSize;
	input >> numSize;
	if(numSize <= 0)
	{
		cerr << "The input numbers error!" << endl;
		return -1;
	}

	vector<int> numVec;
	int tmp;
	while(input >> tmp)
	{
		numVec.push_back(tmp);
	}
	
	output << "The input number is: " << endl;
	for(auto &n: numVec)
	{
		output << n << " ";
	}
	output << endl;

/*********The sort algorithm begin********/
    vector<int> res = quickSort(numVec);
/*********The sort algorithm end**********/

	output << "The sorted number is: " << endl;
	for (auto &n: res)
	{
		output << n << " ";
	}
	output << endl;

	return 0;
}

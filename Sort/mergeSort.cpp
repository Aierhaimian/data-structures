#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void merge(vector<int> &v, vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }else
        {
            v.push_back(v2[j]);
            j++;
        }
    }

    while (i < n1)
    {
        v.push_back(v1[i]);
        i++;
    }

    while (j < n2)
    {
        v.push_back(v2[j]);
        j++;
    }
}

void mergeSort(vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1)
        return;

    vector<int> v1, v2;
    int i = 0;
    while (i < n)
    {
        if (i < n/2)
        {
            v1.push_back(vec[i]);
        }else{
            v2.push_back(vec[i]);
        }
        i++;
    }

    mergeSort(v1);
    mergeSort(v2);

    vec.clear();
    merge(vec, v1, v2);
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
    mergeSort(numVec);
/*********The sort algorithm end**********/

	output << "The sorted number is: " << endl;
	for (auto &n: numVec)
	{
		output << n << " ";
	}
	output << endl;

	return 0;
}

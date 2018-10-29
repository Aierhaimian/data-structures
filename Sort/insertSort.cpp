#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> insertSort(vector<int> &vec)
{
	for (int i=1; i<vec.size(); i++)
	{
		int tmp = vec[i];
		int j = i - 1;
		for (; j>=0; j--)
		{
			if (vec[j] > tmp)
			{
				vec[j+1] = vec[j];
			}else
			{
				break;
			}
		}
		vec[j+1] = tmp;
	}
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

	vector<int> res = insertSort(numVec);

	output << "The sorted number is: " << endl;
	for (auto &n: res)
	{
		output << n << " ";
	}
	output << endl;

	return 0;
}

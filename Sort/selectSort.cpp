#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> selectSort(vector<int> &vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		int minNum = vec[i];
		int minIndex = i;
		for (int j=i+1; j<vec.size(); j++)
		{
			if (vec[j] < minNum)
			{
				minNum = vec[j];
				minIndex = j;
			}
		}
		vec[minIndex] = vec[i];
		vec[i] = minNum;
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

	vector<int> res = selectSort(numVec);

	output << "The sorted number is: " << endl;
	for (auto &n: res)
	{
		output << n << " ";
	}
	output << endl;

	return 0;
}

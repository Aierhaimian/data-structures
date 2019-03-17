#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int binarySearchLast(vector<int> &vec, int value, int low, int high)
{
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if (vec[mid] == value)
        {
            if(mid == vec.size()-1 || vec[mid+1] != value)
                return mid+1;
            else
                low = mid + 1;
        }
        else if (vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchLastSmall(vector<int> &vec, int value, int low, int high)
{
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if (vec[mid] <= value)
        {
            if(mid == vec.size()-1 || vec[mid+1] > value)
                return mid+1;
            else
                low = mid + 1;
        }
        else
            low = mid + 1;
    }

    return -1;
}

int binarySearchFirst(vector<int> &vec, int value, int low, int high)
{
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if (vec[mid] == value)
        {
            if(mid == 0 || vec[mid-1] != value)
                return mid+1;
            else
                high = mid - 1;
        }
        else if (vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchFirstLarge(vector<int> &vec, int value, int low, int high)
{
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if (vec[mid] >= value)
        {
            if(mid == 0 || vec[mid-1] < value)
                return mid+1;
            else
                high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return -1;
}

int binarySearchInternal(vector<int> &vec, int value, int low, int high)
{
    while(low <= high)
    {
        int mid = low + ((high-low)>>1);
        if (vec[mid] == value)
            return mid + 1;
        else if (vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchRecursive(vector<int> &vec, int value, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + ((high -low)>>1);
    
    if(vec[mid] == value)
        return mid + 1;
    else if(vec[mid] < value)
        binarySearchRecursive(vec, value, mid+1, high);
    else
        binarySearchRecursive(vec, value, low, mid-1);
}

int binarySearch(vector<int> &vec, int value)
{
    int low = 0;
    int high = vec.size() - 1;
    //return binarySearchInternal(vec, value, low, high);
    //return binarySearchRecursive(vec, value, low, high);
    //return binarySearchFirst(vec, value, low, high);
    //return binarySearchLast(vec, value, low, high);
    //return binarySearchFirstLarge(vec, value, low, high);
    return binarySearchLastSmall(vec, value, low, high);
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
	for (int i=0; i<numSize; i++)
	{
        input >> tmp;
		numVec.push_back(tmp);
	}
	
	output << "The search array is:" << endl;
	for(auto &n: numVec)
	{
		output << n << " ";
	}
	output << endl;

    int value;
    input >> value;
    output << "The search number is:"<< endl;
    output << value << endl;

/*********The binary Search algorithm begin********/
    int res = binarySearch(numVec, value);
/*********The binary Search algorithm end**********/

	output << "The result is: " << endl;
	output << res << endl;

	return 0;
}

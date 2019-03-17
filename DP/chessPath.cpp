#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class ChessPath
{
public:
    ChessPath() = default;
    ChessPath(vector<vector<int>> vec)
        :cb(vec)
    {
        minPath = INT_MAX;
        n = vec.size();
        /* cout << "n = " << n << endl; */
        mem.resize(n);
        for (int i=0; i<n; i++)
            mem[i].resize(n);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                mem[i][j] = 0;
    }

    void minDistBT(int i, int j, int dist)
    {
        if (i == n-1 && j == n-1)
        {
            dist += cb[i][j];
            if (dist < minPath)
                minPath = dist;
            return;
        }

        if (i < n-1)
            minDistBT(i+1, j, dist+cb[i][j]);
        if (j < n-1)
            minDistBT(i, j+1, dist+cb[i][j]);
    }

    void minDistDP()
    {
        vector<vector<int>> states(n, vector<int>(n, 0));
        int sum = 0;
        for (int j=0; j<n; j++)
        {
            sum += cb[0][j];
            states[0][j] = sum;
        }
        sum = 0;
        for (int i=0; i<n; i++)
        {
            sum += cb[i][0];
            states[i][0] = sum;
        }

        for (int i=1; i<n; i++)
        {
            for (int j=1; j<n; j++)
            {
                states[i][j] = cb[i][j] + min(states[i-1][j], states[i][j-1]);
            }
        }
        minPath = states[n-1][n-1];
    }

    int minDistMem(int i, int j)
    {
        if (i == 0 && j == 0)
            return cb[0][0];
        if (mem[i][j] > 0)
            return mem[i][j];
        int minLeft = INT_MAX;
        if (j-1 >= 0)
            minLeft = minDistMem(i, j-1);
        int minUp = INT_MAX;
        if (i-1 >= 0)
            minUp = minDistMem(i-1, j);
        
        int currMinDist = cb[i][j] + min(minLeft, minUp);
        mem[i][j] = currMinDist;
        return currMinDist;
    }

    int getPath()
    {
        return minPath;
    }
private:
    int minPath;
    vector<vector<int>> cb;
    vector<vector<int>> mem;
    int n;
};

int main()
{
    vector<vector<int>> vec = {{1,3,5,9},{2,1,3,4},{5,2,6,7},{6,8,4,3}};

    ChessPath cp(vec);

    /* cp.minDistBT(0, 0, 0); */
    /* cp.minDistDP(); */

    /* cout << "The shortest chess path is " << cp.getPath() << endl; */
    cout << "The shortest chess path is " << cp.minDistMem(vec.size()-1, vec[0].size()-1) << endl;

    return 0;
}

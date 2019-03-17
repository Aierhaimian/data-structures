#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class TrianglePath
{
public:
    TrianglePath() = default;
    TrianglePath(int h, vector<vector<int>> &vec)
        :hight(h), triNum(vec)
    {
        minPath = INT_MAX;
        states.resize(vec.size());
        for (size_t i=0; i<vec.size(); i++)
            states[i].resize(vec[hight].size());
        mem.resize(vec.size());
        for (size_t i=0; i<vec.size(); i++)
            mem[i].resize(vec[hight].size());
        for (size_t i=0; i<vec.size(); i++)
            for (size_t j=0; j<vec[i].size(); j++)
                mem[i][j] = false;
    }

    void Backtracking(int i, int j, int val)
    {
        if (i == hight)
        {
            if (val < minPath)
                minPath = val;
            return;
        }

        Backtracking(i+1, j, val+triNum[i+1][j]);
        Backtracking(i+1, j+1, val+triNum[i+1][j+1]);
    }

    void memBT(int i, int j, int val)
    {
        if (i == hight)
        {
            if (val < minPath)
                minPath = val;
            return;
        }

        if (mem[i][j])
            return;
        mem[i][j] = true;

        memBT(i+1, j, val+triNum[i+1][j]);
        memBT(i+1, j+1, val+triNum[i+1][j+1]);
    }

    void DP()
    {
        for (size_t i=0; i<triNum.size(); i++)
            for (size_t j=0; j<triNum[i].size(); j++)
                states[i][j] = -1;
        
        states[0][0] = triNum[0][0];

        for (size_t i=1; i<triNum.size(); i++)
        {
            for (size_t j=0; j< triNum[i].size(); j++)
            {
                if (j == 0)
                    states[i][j] = states[i-1][j] + triNum[i][j];
                else if (j == triNum[i].size() - 1)
                    states[i][j] = states[i-1][j-1] + triNum[i][j];
                else
                    states[i][j] = min(states[i-1][j-1]+triNum[i][j], states[i-1][j]+triNum[i][j]);
            }
        }

        for (size_t i=0; i<states[hight].size(); i++)
        {
            if (states[hight][i] < minPath)
                minPath = states[hight][i];
        }
    }

    int get()
    {
        return minPath;
    }
private:
    int minPath;
    int hight;
    vector<vector<int>> triNum;
    vector<vector<bool>> mem;
    vector<vector<int>> states;
};

int main()
{
    vector<vector<int>> vec = {{5}, {7,8}, {2,3,4}, {4,9,6,1}, {2,7,9,4,5}};

    TrianglePath tri(vec.size()-1, vec);

    //tri.Backtracking(0, 0, vec[0][0]);
    //tri.memBT(0, 0, vec[0][0]);
    tri.DP();

    cout << tri.get() << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class CoinChange
{
public:
    CoinChange() = default;
    CoinChange(vector<int> vec, int val)
        :coinVal(vec), changeVal(val)
    {
        minCoin = INT_MAX;
    }

    int getMinCoin()
    {
        return minCoin;
    }

    void minCoinBT(int coinNum, int changeNum)
    {
        if (changeNum > changeVal)
            return;
        if (changeNum == changeVal)
        {
            if (coinNum < minCoin)
                minCoin = coinNum;
            return;
        }
        
        if (changeNum < changeVal)
            for (size_t i=0; i<coinVal.size(); i++)
                minCoinBT(coinNum+1, changeNum+coinVal[i]);
    }

    void minCoinDP()
    {
        vector<vector<bool>> states(changeVal, vector<bool>(changeVal+1, false));
        for (size_t i=0; i<coinVal.size(); i++)
            states[0][coinVal[i]] = true;

        for (int i=1; i<changeVal; i++)
        {
            for (int j=1; j<=changeVal; j++)
            {
                if (states[i-1][j])
                {
                    for (size_t k=0; k<coinVal.size(); k++)
                    {
                        if (j+coinVal[k] <= changeVal)
                            states[i][j+coinVal[k]] = true;
                        if (states[i][changeVal])
                        {
                            minCoin = i+1;
                            return;
                        }
                    }
                }
            }
        }
    }
private:
    vector<int> coinVal;
    int changeVal;
    int minCoin;
};

int main()
{
    vector<int> vec = {1,3,5};
    int val = 9;

    CoinChange cc(vec, val);

    /* cc.minCoinBT(0, 0); */
    cc.minCoinDP();

    cout << "We need min coin num is: " << cc.getMinCoin() << endl;

    return 0;
}

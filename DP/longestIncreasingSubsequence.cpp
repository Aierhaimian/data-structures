#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class LongestIncresingSubsequence
{
public:
    LongestIncresingSubsequence() = default;
    LongestIncresingSubsequence(vector<int> vec)
        :arr(vec)
    {
        maxLen = INT_MIN;
        n = arr.size();
    }

    int getLen()
    {
        return maxLen;
    }

    void maxLenBT(int q, int x, int len)
    {
        if (q == n)
        {
            if (len > maxLen)
                maxLen = len;
            return;
        }

        for (int i=q; i<n; i++)
        {
            if (x < arr[i])
                maxLenBT(i+1, arr[i], len+1);
        }
    }

    void maxLenDP()
    {
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i=1; i<n; i++)
        {
            dp[i] = 1;
            for (int j=0; j<i; j++)
            {
                if (arr[i] > arr[j] && dp[j] +1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxLen)
                maxLen = dp[i];
        }
    }
private:
    int maxLen;
    vector<int> arr;
    int n;
};

int main()
{
    vector<int> vec = {2,9,3,6,5,1,7};
    
    LongestIncresingSubsequence lis(vec);

    /* lis.maxLenBT(0, 0, 0); */
    lis.maxLenDP();

    cout << "The longest increasing subsequence is: " << lis.getLen() << endl;
}

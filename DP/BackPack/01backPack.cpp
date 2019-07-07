#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 问题描述：
// 有n件物品和一个容量为W的背包。放入第i件物品的重量是w(i)，得到的价值是v(i)。求解将哪些物品装入背包可使价值最大。
// 基本思路：
// 特点：每种物品仅有一件，可以选择放入或者不放
// 状态：F[i, w]表示前i件物品恰好放入容量为w的背包可以获得的最大价值
// 状态转移方程：F[i, w] = max(F[i-1, w], F[i-1, w-w(i)] + v(i))

// Recursive
// Time  Complexity: O(n*2^n)
// Space Complexity: O(1)
class Solution1 {
public:
    int backPack01(const vector<int> &w, const vector<int> &v, int W) {
        int n = w.size();
        return maxValue(w, v, n-1, W);
    }
private:
    // 用[0...index]的物品，填充容积为W的背包获得的最大价值
    int maxValue(const vector<int> &w, const vector<int> &v, int index, int W) {
        if (index < 0 || W <=0 ) return 0;

        int res = maxValue(w, v, index-1, W);
        if (W >= w[index])
            res = max(res, maxValue(w, v, index-1, W-w[index])+v[index]);
        return res;
    }
};

// Memory Search
// Time  Complexity: O(n*2^n)
// Space Complexity: O(n*W)
class Solution2 {
public:
    int backPack01(const vector<int> &w, const vector<int> &v, int W) {
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(W+1, -1));
        return maxValue(w, v, n-1, W);
    }
private:
    vector<vector<int>> memo;
    // 用[0...index]的物品，填充容积为W的背包获得的最大价值
    int maxValue(const vector<int> &w, const vector<int> &v, int index, int W) {
        if (index < 0 || W <=0 ) return 0;

        if (memo[index][W] != -1) return memo[index][W];

        int res = maxValue(w, v, index-1, W);
        if (W >= w[index])
            res = max(res, maxValue(w, v, index-1, W-w[index])+v[index]);
        return memo[index][W] = res;
    }

};

// Dynamic Programming
// Time  Complexity: O(n*W)
// Space Complexity: O(n*W)
class Solution3 {
public:
    int backPack01(const vector<int> &w, const vector<int> &v, int W) {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0) return 0;

        vector<vector<int>> memo(n, vector<int>(W+1, -1));

        for (int j = 0; j<=W; j++)
            memo[0][j] = (j >= w[0] ? v[0] : 0);

        for (int i=1; i<n; i++)
            for (int j=0; j<=W; j++) {
                memo[i][j] = memo[i-1][j];
                if (j >= w[i])
                    memo[i][j] = max(memo[i][j], v[i] + memo[i-1][j-w[i]]);
            }
        return memo[n-1][W];
    }
};

int main()
{

    return 0;
}


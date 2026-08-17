#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int memo[501][501];
    int prefix[502];

    int getSum(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

    int solve(int i, int j, const std::vector<int>& stoneValue) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = std::max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (leftSum > rightSum) {
                maxScore = std::max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else {
                maxScore = std::max(maxScore, leftSum + std::max(solve(i, k, stoneValue), solve(k + 1, j, stoneValue)));
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(int), -1);

        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};
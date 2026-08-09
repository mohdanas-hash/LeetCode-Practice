#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> suffix_sum(n, 0);
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix_sum[i];
                } else {
                    for (int X = 1; X <= 2 * M; ++X) {
                        int next_M = max(M, X);
                        dp[i][M] = max(dp[i][M], suffix_sum[i] - dp[i + X][next_M]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};
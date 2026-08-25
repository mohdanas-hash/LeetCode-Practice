#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        std::vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currentSum = 0;

            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                currentSum += stoneValue[i + k - 1];
                int nextDiff = (i + k < n) ? dp[(i + k) % 4] : 0;
                maxDiff = std::max(maxDiff, currentSum - nextDiff);
            }
            
            dp[i % 4] = maxDiff;
        }

        int aliceDiff = dp[0];
        if (aliceDiff > 0) return "Alice";
        if (aliceDiff < 0) return "Bob";
        return "Tie";
    }
};
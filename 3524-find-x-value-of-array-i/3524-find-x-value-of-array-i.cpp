class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int rem = x % k;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * rem) % k] += dp[r];
                }
            }
            next_dp[rem] += 1;

            dp = next_dp;

            for (int r = 0; r < k; ++r) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};
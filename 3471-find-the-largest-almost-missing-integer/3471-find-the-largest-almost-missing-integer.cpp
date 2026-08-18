class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // Case 1: k == 1 (Woh sabse bada element jo exact 1 baar aaya ho)
        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) ans = max(ans, val);
            }
            return ans;
        }

        // Case 2: k == n (Array ka maximum element)
        if (k == n) {
            int ans = -1;
            for (int x : nums) ans = max(ans, x);
            return ans;
        }

        // Case 3: 1 < k < n (Only first or last element valid ho sakte hain)
        int ans = -1;
        if (freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if (freq[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);

        return ans;
    }
};
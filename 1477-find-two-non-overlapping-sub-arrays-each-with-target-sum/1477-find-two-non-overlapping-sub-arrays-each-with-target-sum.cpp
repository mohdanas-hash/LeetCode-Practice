class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        int curr_min = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, len + min_len[left - 1]);
                }
                curr_min = min(curr_min, len);
            }

            min_len[right] = curr_min;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int min_idx = 0;
        int max_idx = 0;
        
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[min_idx]) {
                min_idx = k;
            }
            if (nums[k] > nums[max_idx]) {
                max_idx = k;
            }
        }
        
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);
        
        int option1 = j + 1;
        int option2 = n - i;
        int option3 = (i + 1) + (n - j);
        
        return min({option1, option2, option3});
    }
};
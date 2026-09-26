class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            curr_max = max(nums[i], curr_max + nums[i]);
            max_so_far = max(max_so_far, curr_max);
            
            curr_min = min(nums[i], curr_min + nums[i]);
            min_so_far = min(min_so_far, curr_min);
        }
        
        return max(max_so_far, abs(min_so_far));
    }
};
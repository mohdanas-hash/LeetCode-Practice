class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int n = nums.size();
        unordered_set<int> window;

        while (high < n) {
            if (window.count(nums[high])) {
                return true;
            }

            window.insert(nums[high]);
            
            if (high - low >= k) {
                window.erase(nums[low]);
                low++;
            }
            high++;
        }  
        return false;
    }
};
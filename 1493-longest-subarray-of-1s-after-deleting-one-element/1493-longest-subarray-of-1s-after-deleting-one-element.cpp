class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int , int> mp;
        int low=0;
        int high=0;
        int n=nums.size();
        while(high<n){
            mp[nums[high]]++;

            if(mp[0]>1){
                mp[nums[low]]--;
                low++;
            }
            
            high++;

        }return high-low-1;
    }
};
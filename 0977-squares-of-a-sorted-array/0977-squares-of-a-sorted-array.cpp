class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> nums2;
        for(int i=0; i<nums.size(); i++){
           int x =nums[i]*nums[i];
           nums2.push_back(x);
           

        }
        sort(nums2.begin(),nums2.end());
        return nums2;
        
    }
};
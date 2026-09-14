class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> nums2;
        for(int i=0; i<nums.size(); i++){
            nums2.push_back(nums[i]*nums[i]);
        }  
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size(); j++){
                if(nums2[i]>nums2[j]){
                    swap(nums2[i], nums2[j]);
                }
                
            }
        }
        return nums2;
        
    }
};
        
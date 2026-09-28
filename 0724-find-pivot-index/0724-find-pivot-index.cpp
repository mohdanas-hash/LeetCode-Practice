class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size(); i++){
            sum=sum+nums[i]; 
        }
        int left=0;
        int right=0;
        for(int i=0; i<nums.size(); i++){
            if(i>0){
                left+=nums[i-1];
            }
            right=sum-nums[i]-left;
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};
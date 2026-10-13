class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum= 0;
        int min_length=INT_MAX;

        for(int high=0; high<nums.size(); high++){
            sum=sum+nums[high];
            
            while(sum>=target){
 
                min_length=min(min_length,high-low+1);
                sum=sum-nums[low];
                low++;
            }
        
        }
        if(min_length==INT_MAX){
            return 0;
        }
        return min_length;
    }
};
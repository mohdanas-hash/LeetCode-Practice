class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int zero=0;
        int max_num=0;

        for(int high=0; high<n; high++){
            if(nums[high]==0){
                zero++;
            }
            while(zero>k){
                if(nums[low]==0) zero--;
                low++;
            }
            max_num=max(max_num, high-low+1);
        }
        return max_num;
    }
};
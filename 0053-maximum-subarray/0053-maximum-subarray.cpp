class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=nums[0];
        int bestn=nums[0];
        for(int i = 1; i<n; i++){
            int v1=bestn+nums[i];
            int v2=nums[i];
            bestn=max(v1,v2);
            sum=max(sum, bestn);
        }return sum;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pro = nums[0];
        int bestn = nums[0];
        int worstn=nums[0];

        for(int i = 1; i<n; i++){
            int v1=bestn*nums[i];
            int v2=nums[i];
            int v3=worstn*nums[i];

            int next_best=max({v1,v2,v3});
            worstn=min({v1,v2,v3});
            bestn=next_best;

            pro=max(pro ,bestn);
        }return pro;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int zero=0;
        int one=0;
        int len=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zero++;
            else one++;
            int diff=zero-one;
            if(diff==0){
                len=i+1;
            }
            else if(mp.find(diff)!=mp.end()){
                len=max(len, i-mp[diff]);
            }
            else{
                mp[diff]=i;
            }
        }return len;
    }
};
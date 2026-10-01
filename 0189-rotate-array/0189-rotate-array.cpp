class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> arr;
        for(int i=n-k; i<n; i++){
           arr.push_back(nums[i]);
        }
        for(int j=0; j<n-k; j++){
            arr.push_back(nums[j]);
        }
        nums=arr;

    }
};
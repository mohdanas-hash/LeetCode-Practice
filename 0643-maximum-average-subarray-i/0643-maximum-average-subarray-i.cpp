class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=k-1;
        double sum=0;
        for(int i =0; i<=high; i++){
            sum=sum+nums[i];
        }
        double mx_avg=sum;
        while(high<n-1){
            high++;
            low++;
            // if(high==n) break;
            sum=sum+nums[high]-nums[low-1];
            mx_avg=max(mx_avg,sum);
        }
        return mx_avg/k;
    }
};
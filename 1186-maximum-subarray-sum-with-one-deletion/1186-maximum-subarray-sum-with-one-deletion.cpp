class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int sum=arr[0];
        int onedelete=arr[0];
        int nodelete=arr[0];
        int i=arr[0];

        for(int i=1; i<arr.size(); i++){
            onedelete = max(nodelete, onedelete + arr[i]);
            nodelete = max(arr[i], nodelete + arr[i]);
            sum = max({sum, nodelete, onedelete});
        }return sum;
    }
};
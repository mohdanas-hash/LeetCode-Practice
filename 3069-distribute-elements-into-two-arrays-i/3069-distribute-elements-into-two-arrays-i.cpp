class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        // First operation: append nums[0] to arr1
        arr1.push_back(nums[0]);
        // Second operation: append nums[1] to arr2
        arr2.push_back(nums[1]);

        // Subsequent operations starting from index 2
        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr2 into arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};
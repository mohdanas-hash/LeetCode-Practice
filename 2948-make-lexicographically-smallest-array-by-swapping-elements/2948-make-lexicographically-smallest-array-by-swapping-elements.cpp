class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && sortedNums[j + 1].first - sortedNums[j].first <= limit) {
                j++;
            }

            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(sortedNums[k].second);
            }
            sort(indices.begin(), indices.end());

            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sortedNums[i + k].first;
            }

            i = j + 1;
        }

        return result;
    }
};
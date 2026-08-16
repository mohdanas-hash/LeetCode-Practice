#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> pancakeSort(std::vector<int>& arr) {
        std::vector<int> result;
        int n = arr.size();

        for (int value = n; value > 0; --value) {
            int idx = 0;
            while (arr[idx] != value) {
                idx++;
            }

            if (idx == value - 1) {
                continue;
            }

            if (idx != 0) {
                result.push_back(idx + 1);
                std::reverse(arr.begin(), arr.begin() + idx + 1);
            }

            result.push_back(value);
            std::reverse(arr.begin(), arr.begin() + value);
        }

        return result;
    }
};
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(const std::vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Search left half for lower bound
                } else {
                    left = mid + 1;  // Search right half for upper bound
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bound;
    }
};
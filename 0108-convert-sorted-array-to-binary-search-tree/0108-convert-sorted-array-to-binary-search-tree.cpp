class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto build = [&](auto& self, int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int mid = l + (r - l) / 2;
            return new TreeNode(nums[mid], self(self, l, mid - 1), self(self, mid + 1, r));
        };
        return build(build, 0, nums.size() - 1);
    }
};
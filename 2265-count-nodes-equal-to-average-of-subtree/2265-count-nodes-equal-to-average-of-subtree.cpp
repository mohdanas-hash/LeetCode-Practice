class Solution {
public:
    int matchingNodeCount = 0;

    // Helper function returning {subtree_sum, subtree_node_count}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int currentSum = leftSum + rightSum + root->val;
        int currentCount = leftCount + rightCount + 1;

        if (currentSum / currentCount == root->val) {
            matchingNodeCount++;
        }

        return {currentSum, currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodeCount;
    }
};
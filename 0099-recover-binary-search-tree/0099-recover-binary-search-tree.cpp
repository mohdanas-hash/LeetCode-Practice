/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        auto checkOrder = [&](TreeNode* node) {
            if (prev != nullptr && prev->val > node->val) {
                if (first == nullptr) {
                    first = prev;
                }
                second = node;
            }
            prev = node;
        };

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                checkOrder(curr);
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr (rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Create temporary thread back to curr
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Thread already exists: remove it and visit curr
                    pred->right = nullptr;
                    checkOrder(curr);
                    curr = curr->right;
                }
            }
        }

        if (first != nullptr && second != nullptr) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        buildString(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        return buildTree(ss);
    }

private:
    void buildString(TreeNode* node, string& out) {
        if (!out.empty()) {
            out.push_back(',');
        }
        if (!node) {
            out.push_back('#');
            return;
        }
        out += to_string(node->val);
        buildString(node->left, out);
        buildString(node->right, out);
    }

    TreeNode* buildTree(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',') || token.empty()) {
            return nullptr;
        }
        if (token == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(token));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        return node;
    }
};
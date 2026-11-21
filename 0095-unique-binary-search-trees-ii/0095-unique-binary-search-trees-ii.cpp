#include <vector>

class Solution {
private:
    // Deep-copies a BST structure while shifting every node's value by `offset`
    TreeNode* cloneWithOffset(const TreeNode* node, int offset) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode* copy = new TreeNode(node->val + offset);
        copy->left = cloneWithOffset(node->left, offset);
        copy->right = cloneWithOffset(node->right, offset);
        return copy;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        // dp[len] stores all structurally unique BSTs built with values [1 ... len]
        std::vector<std::vector<TreeNode*>> dp(n + 1);
        dp[0] = {nullptr};

        for (int len = 1; len <= n; ++len) {
            // Choose every possible value `root_val` in [1 ... len] as the root
            for (int root_val = 1; root_val <= len; ++root_val) {
                int left_len = root_val - 1;
                int right_len = len - root_val;

                // Combine every valid left subtree with every valid right subtree
                for (TreeNode* left_tree : dp[left_len]) {
                    for (TreeNode* right_tree : dp[right_len]) {
                        TreeNode* root = new TreeNode(root_val);
                        // Left subtree already uses [1 ... root_val - 1], so no offset needed
                        root->left = cloneWithOffset(left_tree, 0);
                        // Right subtree uses [root_val + 1 ... len], so shift [1 ... right_len] by root_val
                        root->right = cloneWithOffset(right_tree, root_val);
                        dp[len].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};
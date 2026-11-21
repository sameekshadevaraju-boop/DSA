#include <vector>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left subtree: visit current node and move right
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor (rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Establish temporary thread back to curr, then explore left subtree
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Thread already exists: left subtree is finished; restore tree and visit curr
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
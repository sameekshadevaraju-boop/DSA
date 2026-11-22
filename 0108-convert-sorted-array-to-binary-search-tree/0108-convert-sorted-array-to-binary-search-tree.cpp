#include <vector>

class Solution {
private:
    TreeNode* buildBST(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Overflow-safe midpoint selection guarantees left and right subtree sizes differ by at most 1
        int mid = left + ((right - left) >> 1);

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        return buildBST(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};
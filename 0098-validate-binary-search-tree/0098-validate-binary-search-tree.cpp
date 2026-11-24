class Solution {
public:
    bool check(TreeNode* root, long long min, long long max) {
        if (root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return check(root->left, min, root->val) &&
               check(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
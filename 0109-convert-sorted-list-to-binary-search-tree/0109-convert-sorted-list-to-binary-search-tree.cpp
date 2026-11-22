class Solution {
private:
    // Simulates an inorder traversal of the resulting BST while advancing `curr` linearly
    TreeNode* buildInorder(ListNode*& curr, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + ((right - left) >> 1);

        // 1. Recursively build the left subtree first (consumes first half of list nodes)
        TreeNode* left_child = buildInorder(curr, left, mid - 1);

        // 2. `curr` now points directly to the middle element for this subtree
        TreeNode* root = new TreeNode(curr->val);
        root->left = left_child;

        // Advance the linked list pointer to the next ascending element
        curr = curr->next;

        // 3. Recursively build the right subtree (consumes remaining half of list nodes)
        root->right = buildInorder(curr, mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Count total nodes in O(N) to establish balanced index bounds
        int n = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            ++n;
        }

        return buildInorder(head, 0, n - 1);
    }
};
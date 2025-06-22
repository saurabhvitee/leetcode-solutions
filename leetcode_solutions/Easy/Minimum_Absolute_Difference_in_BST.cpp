/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Recurse in left first
        inorderTraversal(root->left);

        // Process the root node and write your logic here
        if (prev != nullptr) {
            minDiff = min(minDiff, abs(root->val - prev->val));
            cout << prev->val << " " << root->val << endl;
        }

        // Now currNode will become previous node
        prev = root;

        // Recurse in right subtree
        inorderTraversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        // Reason because inorderTraversal is sorted in BST - Binary search tree. 
        // Here I can apply algorithm on root node between Recurse(left subtree) and Recurse(right subtree).
        inorderTraversal(root);
        return minDiff;
    }
};
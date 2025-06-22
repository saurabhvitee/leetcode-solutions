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
    int minDepth(TreeNode* root) {
        // Base case if root node is null 
        if (root == nullptr)
            return 0;

        // Base case for leaf node. 
        if (root->left == nullptr and root->right == nullptr) {
            return 1;
        }

        if (root->left == nullptr) {
            // Left subtree is null only call right subtree
            return minDepth(root->right) + 1;
        } else if (root->right == nullptr) {
            // If right subtree is null only call left subtree
            return minDepth(root->left) + 1;
        } else
            // Else call in both the direction, whatever is minimum return that to parent node. 
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == nullptr)
            return nullptr;

        // If you find any node p and q, return that node
        if (root == p or root == q)
            return root;

        // Recurse in both the directions
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If you find something from left subtree only and right is nullptr ->
        // return left If you find somethinng from right subtree only and left
        // is nullptr -> return right If you find something from both the ends
        // -> return root;
        if (left and right)
            return root;
        else if (left)
            return left;
        else
            return right;
    }
};
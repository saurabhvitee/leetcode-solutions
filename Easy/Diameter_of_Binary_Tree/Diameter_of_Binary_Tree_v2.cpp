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
    int ans = 0;

    int helper(TreeNode* root) {
        // If it is a null node return 0 to parent node since there is no edge. 
        if (root == nullptr)
            return 0;

        // If it is a leaf node return 1 to parent node for parent-child edge
        if (root->left == nullptr and root->right == nullptr)
            return 1; // Leaf node

        int left = helper(root->left);
        int right = helper(root->right);

        // At every node diameter is sum of longest left subtree + right subtree. 
        int diameter = left + right;
        ans = max(ans, diameter);

        // At every node return the maximum path to parent by adding 1 for child-parent edge.
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0; // If node is nullptr
        helper(root);
        return ans;
    }
};
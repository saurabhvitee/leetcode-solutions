/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int helper(TreeNode* root){
        if(root == nullptr) return 0;

        if(root->left == nullptr and root->right == nullptr) return 1; // Leaf node 

        int left = helper(root->left);
        int right = helper(root->right);

        int diameter = left+right;
        ans = max(ans,diameter);

        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0; // If node is nullptr 
        helper(root);
        return ans;
    }
};
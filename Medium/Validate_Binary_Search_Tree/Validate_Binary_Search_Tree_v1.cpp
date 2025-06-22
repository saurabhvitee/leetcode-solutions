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
    bool isBinaryTreeValidBST(TreeNode* root, long small, long large) {
        if (root == nullptr)
            return true; // a null node is always a valid BST.

        // Any node where we are going via DFS should be in range.
        // If it is in range call further for left and right subtrees you should not return true and end the execution.
        if (root->val > small && root->val < large)
            return isBinaryTreeValidBST(root->left, small, root->val) &&
                   isBinaryTreeValidBST(root->right, root->val, large);
        else
            return false;
    }

    bool isValidBST(TreeNode* root) {
        if(root->left == nullptr and root->right == nullptr) return true;
        // Checking immediate left and right will not work
        // Since any node in left subtree can not be greater than root
        // Any node in right subtree can not be lesser than root.
        // So as soon as we progress into right and left subtrees we will be
        // keeping count of Maximum value for left subtree that any node can not
        // exceed. Minimum value for right subtree that any node can not exeeed.

        // Here important stuff is LONG_MIN and LONG_MAX 
        return isBinaryTreeValidBST(root, LONG_MIN, LONG_MAX);
    }
};
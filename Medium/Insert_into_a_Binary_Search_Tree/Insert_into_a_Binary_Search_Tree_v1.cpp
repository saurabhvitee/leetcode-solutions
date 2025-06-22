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
    void dfs(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        // Now place the value if you have empty right or left

        if (root->left == nullptr and val < root->val) {
            root->left = new TreeNode(val);
            return;
        }

        if (root->right == nullptr and val > root->val) {
            root->right = new TreeNode(val);
            return;
        }

        if (val < root->val) {
            // left direction recurse
            return dfs(root->left, val);
        } else {
            // right direction recurse
            return dfs(root->right, val);
        }

        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If root node is nullptr we can add value here and return
        if (root == nullptr) {
            return new TreeNode(val);
        }

        dfs(root, val);
        return root;
    }
};
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check if both the nodes are nullptr
        if (!p and !q)
            return true;

        // Check if one of the node is nullptr -> return false
        if (!p or !q)
            return false;

        // Check if values are not same
        if (p->val not_eq q->val)
            return false;

        // subsequent calls until we reach till leaf nodes or else we would
        // return in between.
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
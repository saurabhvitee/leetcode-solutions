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
    int closestAns = 0;
    double minDiffTillNow = INT_MAX;

    void dfs(TreeNode* root, double target) {
        if (root == nullptr)
            return;

        // Inorder traversal in sorted order hence let's go with inorder
        // traversal.

        // Recurse in left subtree 
        dfs(root->left, target);

        // Compare the target with this node and if difference is less than
        // previous value then update our closestAns

        if (abs((double)root->val - target) < minDiffTillNow){
            // then we will update our answer.
            minDiffTillNow = abs((double)root->val - target);
            closestAns = root->val;
        }

        // Recurse on right subtree
        dfs(root->right, target);
    }

    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return closestAns;
    }
};
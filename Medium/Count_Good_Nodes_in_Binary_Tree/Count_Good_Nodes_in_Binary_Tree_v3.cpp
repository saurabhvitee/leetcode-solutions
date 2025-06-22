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
    int goodNodes(TreeNode* root) {
        countGoodNodes(root, INT_MIN);
        return ans;
    }


    void countGoodNodes(TreeNode* root, int maxSoFar){
        if(root == nullptr){
            return;
        }

        if(root->val >= maxSoFar)
            ans++;

        countGoodNodes(root->left, max(root->val, maxSoFar));
        countGoodNodes(root->right, max(root->val, maxSoFar));

        return;
    }
};
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
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int ans;

        while (!q.empty()) {
            ans = 0;
            int nodesAtCurrLevel = q.size();
            for (int i = 0; i < nodesAtCurrLevel; i++) {
                auto node = q.front();
                q.pop();

                ans += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
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
    vector<int> largestValues(TreeNode* root) {

        if (root == nullptr)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int nodesAtCurrLevel = q.size() - 1; // 0 based indexing
            int maxAtEachRow = INT_MIN;

            for (int i = 0; i <= nodesAtCurrLevel; i++) {
                // Level wise traversal 
                auto node = q.front();
                q.pop();

                maxAtEachRow = max(node->val, maxAtEachRow);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Push maximum element for current row in answer
            ans.push_back(maxAtEachRow);
        }

        return ans;
    }
};
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0; // If there is no node

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1; // If there is one node

        while (!q.empty()) {

            int qSize = q.size();
            // Level order traversal whatever is in the queue let's process that first then increase the level. 

            for (int i = 0; i < qSize; i++) {
                auto node = q.front();
                q.pop();

                // We have found leaf node and this is first leaf node so this
                // is the answer which is closer to root node.
                if (node->left == nullptr and node->right == nullptr) {
                    return depth;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // increase the depth since you have traversed the whole level 
            depth++;
        }

        return depth;
    }
};
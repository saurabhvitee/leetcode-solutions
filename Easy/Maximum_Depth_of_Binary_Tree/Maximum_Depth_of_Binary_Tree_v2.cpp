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
    int maxDepth(TreeNode* root) {
        // Post order traversal - Recursive solution

        // Base case is important when we are hitting leaf TreeNode
        if (root == nullptr)
            return 0;

        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        stack<pair<TreeNode*, int>> st;

        // Push the root node with depth 1.
        st.push({root, 1});

        int maxDepth = 0; // variable to store max height at each pop

        // Traverse until stack is empty.
        while(!st.empty()){
            auto [node, depth] = st.top();
            st.pop();

            maxDepth = max(maxDepth, depth);

            if(node->left){
                st.push({node->left, depth+1});
            }

            if(node->right){
                st.push({node->right, depth+1});
            }
        }

        return maxDepth;
    }
};
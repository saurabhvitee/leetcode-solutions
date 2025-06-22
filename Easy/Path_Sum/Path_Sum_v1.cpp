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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        stack<pair<TreeNode*, int>> st;

        // Push the root node
        st.push({root, root->val});

        while (!st.empty()) {

            auto [node, currSum] = st.top();
            st.pop();

            // Check if we have reached till leaf TreeNode
            if (not node->left and not node->right)
                if (currSum == targetSum)
                    return true;

            if (node->right)
                st.push({node->right, currSum + node->right->val});

            if (node->left)
                st.push({node->left, currSum + node->left->val});
        }

        return false;
    }
};
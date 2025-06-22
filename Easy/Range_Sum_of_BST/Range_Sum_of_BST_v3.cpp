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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;

        stack<TreeNode*> st;
        st.push(root);

        int rangeSumAns = 0;

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            // if any node is null continue
            if(node == nullptr){
                continue;
            }

            // Only include current node if it is within range [low, high]
            if(node->val >= low and node->val <= high){
                rangeSumAns += node->val;
            }

            // Traverse in left tree if your node->val is greater than low.
            if(node->val > low)
                st.push(node->left);
            
            // Traverse in right if your node->val is lesser than high 
            if(node->val < high)
                st.push(node->right);
        }

        return rangeSumAns;
    }
};
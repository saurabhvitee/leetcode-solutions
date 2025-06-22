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
    int goodNodes(TreeNode* root) {

        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, INT_MIN});

        int countGoodNodes = 0;

        while (!st.empty()) {
            auto [node, currMax] = st.top();
            st.pop();

            if (node->val >= currMax){
                // cout << node->val << " " << currMax << endl;
                countGoodNodes++;
            }

            // Note here we can not initialize with global max variable since that would incorrectly insert global max for all the nodes 
            // Here what we are doing we are calculating max from root to this node and pushing that into stack. 

            // Basically whatever is max till parent node from root, we will insert that for child node.
            currMax = max(currMax, node->val);

            if (node->right)
                st.push({node->right, currMax});

            if (node->left)
                st.push({node->left, currMax});
        }

        return countGoodNodes;
    }
};
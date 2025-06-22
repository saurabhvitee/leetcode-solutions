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
    // globally declare our ans vector 
    vector<int> ans;

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0); // call DFS function with 0 depth, since depth/level of root is 0.
        return ans; // once after the execution our ans vector will have answer 
    }

    void dfs(TreeNode* root, int level){
        if(root == nullptr){
            return;
        }

        // If ans vector size is equal to level means this is first node of this level.
        if(level == ans.size())
            ans.push_back(root->val);
        else
            ans[level] = max(ans[level], root->val); // if you have already seen node at this level then update that
        
        dfs(root->left, level+1);
        dfs(root->right, level+1);
        //return;
    }
};
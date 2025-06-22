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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> anss;
        if(root == NULL){
            return anss;
        }
        queue <TreeNode*> q;
        if(root != NULL)
        q.push(root);
        q.push(NULL);
        vector <vector<int>> ans;
        vector <int> v;
        while(!q.empty())
        {
            if(q.front()==NULL){
                q.pop();
                ans.push_back(v);
                v.clear();
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                TreeNode* temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
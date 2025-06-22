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
    void dfs(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        // Now place the value if you have empty right or left

        if (root->left == nullptr and val < root->val) {
            root->left = new TreeNode(val);
            return;
        }

        if (root->right == nullptr and val > root->val) {
            root->right = new TreeNode(val);
            return;
        }

        if (val < root->val) {
            // left direction recurse
            return dfs(root->left, val);
        } else {
            // right direction recurse
            return dfs(root->right, val);
        }

        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If root node is nullptr we can add value here and return
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // dfs(root, val); // Recursive solution with dfs traversal
        // return root;

        // Let's see iterative traversal. since each step we have a decision to make either left or right
        // so like a linkedList we can always do a iterative traversal in BST. 

        TreeNode* temp = root;

        while(temp != nullptr){
            // Check do we need to move right or left. 
            if(temp->val < val){
                // We need to move right in this case and check if right is free insert then and there.
                if(temp->right == nullptr){
                    temp->right = new TreeNode(val);
                    return root; // Terminate the execution JOB is done
                }
                temp = temp->right;
            }else{
                // We need to move left in this case and check if left is free insert then and there.
                if(temp->left == nullptr){
                    temp->left = new TreeNode(val);
                    return root; // Terminate the program execution
                }
                temp = temp->left;
            }
        }
        return nullptr;
    }
};
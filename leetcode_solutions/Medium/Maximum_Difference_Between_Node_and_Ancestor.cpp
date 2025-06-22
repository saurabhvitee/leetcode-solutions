
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
    int globalResult = 0;

    void calculateMaxDifference(TreeNode* root, int currMax, int currMin) {
        // if (root == nullptr) {
        //     return;
        // }

        int resultAtThisNode =
            max(abs(currMax - root->val), abs(currMin - root->val));
        
        globalResult = max(globalResult, resultAtThisNode); // update global result 

        // Let's update our currMax and currMin
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);

        // call recursion to go into left and right subtrees.
        if(root->left)
            calculateMaxDifference(root->left, currMax, currMin);
        
        if(root->right)
            calculateMaxDifference(root->right, currMax, currMin);
        
        return;
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        calculateMaxDifference(root, root->val, root->val);
        return globalResult;
    }
};
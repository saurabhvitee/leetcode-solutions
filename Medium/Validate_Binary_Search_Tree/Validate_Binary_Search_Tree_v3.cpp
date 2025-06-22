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
    // Nested class object creation is completed.
    class Result {
    public:
        bool isBST;
        long minValue;
        long maxValue;

        Result(bool isBST, long minValue, long maxValue) {
            this->isBST = isBST;
            this->minValue = minValue;
            this->maxValue = maxValue;
        }
    };

    Result validateBSTinPostOrderResultAccumulation(TreeNode* root) {
        // If node is leaf node I can return it's values to top.

        if (root == nullptr) {
            return Result(true, LONG_MAX, LONG_MIN);
        }

        // if (root->left == nullptr and root->right == nullptr)
        //     return Result(true, (long)root->val, (long)root->val);

        // Recurse in left and right subtrees
        Result left = validateBSTinPostOrderResultAccumulation(root->left);

        // If left subtree is not a validBST return false;
        if(!left.isBST) return Result(false, 0, 0); // does not matter what values we are passing 

        Result right = validateBSTinPostOrderResultAccumulation(root->right);

        // If right subtree is not a valid BST return false immediately.
        if(!right.isBST) return Result(false, 0, 0);

        bool isSubTreeValidBST = left.isBST and right.isBST and
                                 root->val > left.maxValue and
                                 root->val < right.minValue;
        
        // Let's update leftMinValue and rightMaxValue that we will send to our parents.
        long subTreeMinValue = min((long)root->val, left.minValue);
        long subTreeMaxValue = max((long)root->val, right.maxValue);

        // Now send Result object to our parent
        return Result(isSubTreeValidBST, subTreeMinValue, subTreeMaxValue);
    }

    bool isValidBST(TreeNode* root) {
        // Since we are adding results from below to upper nodes
        // If root node is having true isBST then we can say tree is perfectly
        // balanced

        return validateBSTinPostOrderResultAccumulation(root).isBST;
    }
};
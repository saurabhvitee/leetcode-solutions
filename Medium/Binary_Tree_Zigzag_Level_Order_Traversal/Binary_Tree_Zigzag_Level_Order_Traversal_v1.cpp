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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        deque<TreeNode*> q;
        q.push_back(root);

        vector<vector<int>> ans;

        while (!q.empty()) {

            int nodesAtCurrLevel = q.size();
            vector<int> eachLevelZigZagNodes;

            if (ans.size() % 2 == 0) {
                for (int i = 0; i < nodesAtCurrLevel; i++) {
                    // At odd level we will simply pop from front and add left
                    // first then right

                    TreeNode* currNode = q.front();
                    q.pop_front();

                    eachLevelZigZagNodes.push_back(currNode->val);

                    if (currNode->left)
                        q.push_back(currNode->left);
                    if (currNode->right)
                        q.push_back(currNode->right);
                }
            } else {
                for (int i = 0; i < nodesAtCurrLevel; i++) {
                    // At even level we will pop from back and add right first
                    // then right but push front push front is very important
                    TreeNode* currNode = q.back();
                    q.pop_back();

                    eachLevelZigZagNodes.push_back(currNode->val);

                    // Since at the same time you can 
                    if (currNode->right)
                        q.push_front(currNode->right);
                    if (currNode->left)
                        q.push_front(currNode->left);
                }
            }

            ans.push_back(eachLevelZigZagNodes);
        }
        return ans;
    }
};
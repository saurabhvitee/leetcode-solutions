/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen =
        vector(501, false); // Since node values are between [1,500]
    vector<int> ans;

    void createGraphFromGivenNodes(TreeNode* root) {
        if (root == nullptr)
            return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val); // undirected graph
            createGraphFromGivenNodes(root->left);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val); // undirected graph
            createGraphFromGivenNodes(root->right);
        }
    }

    void bfs(int node, int level) {
        queue<int> q;
        seen[node] = true;
        q.push(node);

        int bfsLevel = 0; // Initially zero

        while (!q.empty()) {
            // Level by level traversal
            // calculate queue size and traverse all the elements
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                node = q.front();
                q.pop();

                if (bfsLevel == level) {
                    // If distance (bfsLevel) is equal to level (k) 
                    // In this case this node is situated at k distance away from the node 
                    // from where we started bfs. 
                    ans.push_back(node);
                }

                for (int neighbor : graph[node]) {
                    if (!seen[neighbor]) {
                        seen[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            // All the nodes at current level processed, move to next level
            bfsLevel++;
        }

        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Let's create graph for the given tree.
        // Undirected graph created from Tree nodes.
        createGraphFromGivenNodes(root);

        // bfs with level=k
        bfs(target->val, k);

        // return answer variable
        return ans;
    }
};
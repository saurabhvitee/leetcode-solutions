class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});  // Start from depth 1
        int max_depth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            max_depth = max(max_depth, depth);

            if (node->left) {
                q.push({node->left, depth + 1});
            }

            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }

        return max_depth;
    }
};

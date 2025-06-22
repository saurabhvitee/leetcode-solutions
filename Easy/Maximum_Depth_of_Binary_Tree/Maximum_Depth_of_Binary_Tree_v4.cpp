class Solution {

  private:
    // The queue that contains the next nodes to visit, 
    //   along with the level/depth that each node is located.
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;
    
    /**
     * A tail recursion function to calculate the max depth
     *   of the binary tree.
     */
    int next_maxDepth() {
    
      if (next_items.size() == 0) {
        return max_depth;
      }
        
      auto [node, depth] = next_items.front();
      next_items.pop();
  
      max_depth = max(max_depth, depth);

      // Add the nodes to visit in the following recursive calls.
      if (node->left != NULL) {
        next_items.push(make_pair(node->left, depth+1));
      }
      if (node->right != NULL) {
        next_items.push(make_pair(node->right, depth+1));
      }
    
      // The last action should be the ONLY recursive call
      //   in the tail-recursion function.
      return next_maxDepth();
    }
    
  public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) return 0;
        
      // Clear the previous queue.
      std::queue<pair<TreeNode*, int>> empty;
      std::swap(next_items, empty);
      max_depth = 0;
        
      // Push the root node into the queue to kick off the next visit.
      next_items.push(make_pair(root, 1));
        
      return next_maxDepth();
    }
};
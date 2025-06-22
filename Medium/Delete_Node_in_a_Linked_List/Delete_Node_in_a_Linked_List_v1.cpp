/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // We want to delete this node itself
        // This node is storing some data but is that necessary to me ?

        // So what I can do is copy next node's value in current node
        // So current node's value will not be visible to me
        node->val = node->next->val;
        
        // This is second layer of optimization
        // where I am skipping one node

        node->next = node->next->next;
    }
};
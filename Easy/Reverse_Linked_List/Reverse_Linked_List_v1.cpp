/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if(head==nullptr|| head->next==nullptr){
            return head;
        }

        // Recursive call - post order solution 
        // deepest call will be resolved first
        ListNode* newHead = reverseList(head->next);

        // This code will be executed for second last node at first
        // where we will reverse the last 2 nodes and return new reversed list.

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        // return newHead 
        return newHead;
        
    }
};
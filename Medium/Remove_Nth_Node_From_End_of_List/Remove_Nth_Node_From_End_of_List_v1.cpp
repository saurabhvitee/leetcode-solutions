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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        // This condition will only it if size of LL = N 
        // So in this case Nth node from last will be head itself.
        // Hence we are removing head here and returning head->next
        // Very important base case
        if(fast == nullptr) return head->next;

        // Here I am checking fast->next
        // When fast will be at the end slow will be just before the node that
        // we need to delete
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // Here we do not want deleteNode to be in memory and haunt us forever
        // Get rid of deleteNode completely
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return head;
    }
};
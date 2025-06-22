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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while( (l1!=nullptr || l2!=nullptr) || carry!=0){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum+= l2->val;
                l2 = l2->next;
            }

            sum += carry; // Check do we have any carry from previous sum

            // Try to create new node in new list that we want to return
            ListNode* node = new ListNode(sum % 10);

            // Update carry
            carry = sum / 10;

            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
};
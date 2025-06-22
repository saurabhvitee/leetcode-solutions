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
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* oldTail = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            
            if(fast && fast->next){
                oldTail = slow;
            }
            slow = slow->next;
            fast = fast->next->next;

        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(slow != nullptr){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Fixing previous half to next reversed half

        // This is not a mandatory step
        // Doing it for the practice
        oldTail->next = prev;
        int ans = 0;

        while(prev != nullptr){
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return ans;


        
    }
};
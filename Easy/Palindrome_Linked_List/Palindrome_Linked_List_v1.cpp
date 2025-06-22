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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode* firstHalfEnd = endOfFirstHalf(head);
        
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;


        while(p2 != nullptr){
            if(p1->val != p2->val) return false;
            cout << p1-> val << " " << p2->val << endl;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;

    }

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

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
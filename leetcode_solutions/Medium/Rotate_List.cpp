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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }

        while(k>=len) k -= len;
        cout << k << endl;

        if(k == 0) return head;

        int pointer = 1;

        temp = head;
        
        while(pointer < (len-k)){
            temp = temp->next;

            pointer++;
        }
        ListNode* tail = temp;

        ListNode* newHead = temp->next;
        temp = temp->next;

        while(temp->next){
            temp = temp->next;
        }

        temp->next = head;
        tail->next = nullptr;

        return newHead;

    }
};
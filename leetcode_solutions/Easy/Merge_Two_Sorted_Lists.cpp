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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;

        // We will use prev for our traversal i.e. dummy
        // Which will be automatically set to our new head
        // Whether it is list1 or list2 does not matter
        // At the end we can simply return dummy->next 
        // This will be pointing to merged sorted list

        while(list1 && list2){
            if(list1->val < list2->val){
                prev->next = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                list2 = list2->next;
            }

            // Finally move our previous pointer to new added ListNode
            prev = prev->next;
        }

        // If anything is left in list1
        // add that to prev
        if(list1){
            prev->next = list1;
        }

        if(list2){
            prev->next = list2;
        }

        return dummy->next;

    }
};
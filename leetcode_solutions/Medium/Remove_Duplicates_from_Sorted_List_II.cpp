class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Version 1
        // This code is not using while inside while.
        // Efficiently we are tracking duplicate variable
        // if duplicate is True -> prev->next = curr->next
        // else -> prev = curr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        // ListNode* curr = head;

        // bool duplicate = false;

        // while (curr && curr->next) {
        //     if (curr->val == curr->next->val) {
        //         curr = curr->next;
        //         duplicate = true;
        //     } else {
        //         if (duplicate) {
        //             prev->next = curr->next;  // skip all duplicates
        //             duplicate = false;
        //         } else {
        //             prev = curr;
        //         }
        //         curr = curr->next;
        //     }
        // }

        // if (duplicate) {
        //     prev->next = nullptr;
        // }

        // return dummy->next;
        

        // Version 2
        // Here if any value is matching with next node's value
        // while this condition is true, head = head->next
        // As soon as this is done prev->next = head->next
        // if not equal prev = prev->next
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;  // skip the last duplicate
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

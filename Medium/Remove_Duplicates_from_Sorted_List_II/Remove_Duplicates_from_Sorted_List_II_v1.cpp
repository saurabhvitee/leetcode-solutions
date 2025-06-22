class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Version 1
        // This code is not using while inside while.
        // Efficiently we are tracking duplicate variable
        // if duplicate is True -> prev->next = curr->next
        // else -> prev = curr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        bool duplicate = false;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr = curr->next;
                duplicate = true;
            } else {
                if (duplicate) {
                    prev->next = curr->next;  // skip all duplicates
                    duplicate = false;
                } else {
                    prev = curr;
                }
                curr = curr->next;
            }
        }

        if (duplicate) {
            prev->next = nullptr;
        }

        return dummy->next;
    }
};

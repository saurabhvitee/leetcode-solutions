class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // **_Change 1: Edge case handling remains the same_**
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }

        // **_Change 2: Introduce a dummy node to handle left == 1 cleanly_**
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* firstTail = dummy;

        // **_Change 3: Move to the node before the 'left' position_**
        for (int i = 1; i < left; ++i) {
            firstTail = firstTail->next;
        }

        // **_Change 4: Setup for reversing the sublist_**
        ListNode* curr = firstTail->next;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        // **_Change 5: Reverse exactly (right - left + 1) nodes_**
        for (int i = 0; i < (right - left + 1); ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // **_Change 6: Connect reversed part to the rest of the list_**
        firstTail->next->next = curr; // original start becomes tail
        firstTail->next = prev;       // connect previous part to new head

        // **_Change 7: Return the real head_**
        return dummy->next;
    }
};

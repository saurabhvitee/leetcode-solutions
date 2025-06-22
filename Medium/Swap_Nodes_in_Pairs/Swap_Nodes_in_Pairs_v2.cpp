/**
 * Iterative solution for swapping nodes in pairs (d = 2) without using a dummy node.
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // First two nodes to start
        ListNode* newHead = head->next;
        ListNode* prev = NULL;

        while (head != NULL && head->next != NULL) {
            ListNode* first = head;
            ListNode* second = head->next;
            ListNode* nextPair = second->next;

            // Swap
            second->next = first;
            first->next = nextPair;
            if (prev != NULL) {
                prev->next = second;
            }

            // Move pointers
            prev = first;
            head = nextPair;
        }

        return newHead;
    }
};

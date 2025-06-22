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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }

        // Count the total number of Nodes
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            temp = temp->next;
            count++;
        }

        // We need newHead because head will surely change
        ListNode* newHead = nullptr;

        // groupStart variable is to track subsequent tail for every group of
        // size K. ktail will be used to track previous group's tail

        ListNode* groupStart = head;
        ListNode* ktail = nullptr;

        while (count >= k) {

            // Since groupStart will always represent head just before reversing
            // the group after reversing this will become tail for the reversed
            // group so curr = groupStart
            ListNode* curr = groupStart;
            ListNode* next = nullptr;
            ListNode* prev = nullptr;

            // Reverse k Nodes
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // At first when newHead is nullptr, it will set newHead to prev
            // prev is head of first reversed group
            // hence this will execute only first time
            if (!newHead)
                newHead = prev;

            // if ktail already exists means we have done some group reversal
            // prior to this Hence pick that tail from previous group and point
            // it to next group's head next group's head will be prev as
            // previously explained. this will execute from second iteration and
            // onwards. (Skip at first iteration)
            if (ktail)
                ktail->next = prev;

            // Now make previous groupStart to ktail
            // since it has been reversed (the previous group)
            ktail = groupStart;

            // Yayy time for a new groupStart which is curr now.
            groupStart = curr;

            count = count - k;
        }

        // count will stop if less than k elements are remaining
        // in that case we will have some leftover nodes at groupStart
        // leftover nodes will always be less than k otherwise those would have
        // been reversed as part of our crazy algorithm now set those leftover
        // nodes to previous tail
        if (ktail) {
            ktail->next = groupStart;
        }

        return newHead;
    }
};
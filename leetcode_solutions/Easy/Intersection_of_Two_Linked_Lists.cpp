/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        // Risky bet is pA and pB will definietly meet
        // Either at intersection point
        // or nullptr at same time
        // since whatever point will reach nullptr first (is from short LL)
        // till the time second point reaches nullptr
        // first will cover that much distance in long LL.
        // They will be situated at same distance either from "Intersection point"
        // or from End of the lists respectively.
        // Infinite loop will never occur.
        
        while(pA != pB){
            if(!pA){
                pA = headB;
            }else{
                pA = pA->next;
            }

            if(!pB){
                pB = headA;
            }else{
                pB = pB->next;
            }
        }

        return pA;
    }
};
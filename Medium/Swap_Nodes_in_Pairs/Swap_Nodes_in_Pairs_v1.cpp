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
    int d = 2;
    ListNode* swapPairs(ListNode* head) 
    {
    ListNode *cur=head,*prev=NULL,*nex=NULL;
    int x = d;
    while(cur!=NULL&& x>0)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
        x--;
    }
    if(nex!=NULL){
        head->next = swapPairs(nex);
    }
    return prev;   
    }
};
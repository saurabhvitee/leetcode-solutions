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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return false;
        }
        map<ListNode*,int> mp;
        ListNode* temp = head;
        int flag = 0;
        while(temp != NULL)
        {
            if(mp.count(temp))
            {
                flag = 1;
                break;
            }
            mp[temp]++;
            temp = temp->next;
        }
        if(flag == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
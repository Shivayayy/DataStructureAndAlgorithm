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
    ListNode* middle(ListNode* head)
    {
        ListNode *slow =head ,*fast =head->next;
        while(fast && fast->next)
        {
            slow =slow->next;
            fast =fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* first,ListNode* second)
    {
        ListNode *head =NULL;
        ListNode* trav =head;
        while(first && second)
        {
            if(first->val<second->val)
            {
                ListNode* nex =first->next;
                if(!trav)
                {
                    head =first;
                    first->next =NULL;
                    trav =head;
                }
                else
                {
                    trav->next =first;
                    first->next =NULL;
                    trav=trav->next;
                }
                first =nex;
            }
            else
            {
                ListNode* sec =second->next;
                if(!trav)
                {
                    head =second;
                    second->next =NULL;
                    trav =second;
                }
                else
                {
                    trav->next =second;
                    second->next =NULL;
                    trav =trav->next;
                }
                second =sec;
            }
        }
        if(first)trav->next =first;
        else trav->next =second;
        return head;   
    }
    ListNode* sortList(ListNode* node) 
    {
        if(!node || !node->next)return node;
        ListNode* mid =middle(node);
        ListNode* nextHalf=mid->next;
        mid->next = NULL;
        ListNode* fir =sortList(node);
        ListNode* sec =sortList(nextHalf);
        ListNode* head =merge(fir,sec);
        return head;
    }
};
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
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    ListNode* rev(ListNode*head)
    {
        ListNode* temp =head;
        ListNode* prv =NULL;
        while(temp)
        {
            ListNode* nxt =temp->next;
            temp->next =prv;
            prv =temp;
            if(!nxt)return temp;
            temp =nxt;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next)return head;
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode* prv =NULL;
        int i;
        while(slow && fast)
        {
            for(i=1;i<k&&fast->next!=NULL;i++)fast =fast->next;
            if(i!= k)break;
            ListNode* nxt =fast->next;fast->next =NULL;
            ListNode* r =rev(slow);

            if(prv)prv->next =r;
            else head =r;

            prv =slow;
            prv->next =nxt;
            slow =nxt;
            fast =nxt;
        }
        return head;
    }
};
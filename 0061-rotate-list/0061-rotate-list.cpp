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
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next||k==0)return head;
        int len =1;
        ListNode* trav=head;
        while(trav->next)
        {
            len =len+1;
            trav =trav->next;
        }
        if(k%len==0)return head;
        int loop =len-k%len-1;
        trav->next =head;
        trav =head;
        while(loop--)
        {
            trav=trav->next;
        }
        head =trav->next;
        trav->next=NULL;
        return head;
    }
};
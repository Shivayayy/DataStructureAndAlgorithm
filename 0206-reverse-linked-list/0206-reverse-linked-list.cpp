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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head)return head;
        ListNode* prev =NULL;
        ListNode* temp =head;
        while(temp)
        {
            ListNode* next =temp->next;
            temp->next =prev;
            prev =temp;
            if(!next)return temp;
            temp =next;
        }
        return temp;
    }
};
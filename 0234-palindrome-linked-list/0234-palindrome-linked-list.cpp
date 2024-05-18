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
    ListNode* reverse(ListNode* node)
    {
        ListNode* prev =NULL;
        ListNode* temp =node;
        while(temp)
        {
            ListNode *next =temp->next;
            temp->next =prev;
            prev =temp;
            if(!next)return temp;
            temp =next;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow =head ,*fast =head;
        while(fast && fast->next)
        {
            slow =slow->next;
            fast =fast->next->next;
        }
        ListNode* rev =(fast)?reverse(slow->next):reverse(slow);
        while(head!=slow)
        {
            if(head->val != rev->val)return false;
            head =head->next;
            rev =rev->next;
        }
        return true;
    }
};
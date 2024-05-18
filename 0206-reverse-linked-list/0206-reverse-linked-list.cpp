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
    ListNode* recur(ListNode* node)
    {
        if(!node || !node->next)return node;
        ListNode* front =node->next;
        ListNode* newHead =recur(node->next);
        front->next =node;
        node->next =NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return recur(head);
    }
};
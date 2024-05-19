/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    Node* insertDuplicate(Node* head)
    {
        Node* temp =head;
        while(temp)
        {
            Node* newNode = new Node(temp->val);
            newNode->next =temp->next;
            temp->next =newNode;
            temp =temp->next->next;
        }
        return head;
    }
    Node* setRandom(Node* head)
    {
        Node* temp =head;
        while(temp)
        {
            temp->next->random =(temp->random)?temp->random->next:NULL;
            temp =temp->next->next;
        }
        return head;
    }
    Node* reset(Node* head)
    {
        Node* dummy = new Node(0);
        Node* itr = head;
        Node* temp = dummy;
        Node* fast;
        while(itr != NULL) {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) 
    {
        head =insertDuplicate(head);
        head =setRandom(head);
        return reset(head);
    }
};
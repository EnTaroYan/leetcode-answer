/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Solution 1
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while(head)
        {
            if(head->val==val)
                head=head->next;
            else
                break;
        }
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        while(temp->next)
        {
            if(temp->next->val==val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        return head;
    }
};

//Solution 2
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* hhead=new ListNode(val+1);
        hhead->next=head;
        ListNode* node=hhead;
        while(node->next)
        {
            if(node->next->val==val)
                node->next=node->next->next;
            else
                node=node->next;
        }
        return hhead->next;
    }
};
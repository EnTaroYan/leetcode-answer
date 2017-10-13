/*Reverse a singly linked list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//Solution 1
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        ListNode* temp1=NULL;
        ListNode* temp2=head;
        ListNode* temp3=head->next;
        while(1)
        {
            temp2->next=temp1;
            if(temp3==NULL)
                return temp2;
            temp1=temp2;
            temp2=temp3;
            temp3=temp3->next;
        }
    }
};
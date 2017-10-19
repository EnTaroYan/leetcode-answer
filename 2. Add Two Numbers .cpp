/* You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        int sum;
        ListNode* temp=l1;
        ListNode* head=l1;
        while(l1 && l2)
        {
            sum=l1->val+l2->val+carry;
            if(sum>=10)
            {
                l1->val=sum-10;
                carry=1;
            }
            else
            {
                l1->val=sum;
                carry=0;
            }
            temp=l1;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL && l2==NULL)
        {
            if(carry==1)
                temp->next=new ListNode(1);
        }
        else
        {
            if(l2)
            {
                temp->next=l2;
                l1=l2;
            }
            while(carry)
            {
                if(l1==NULL)
                {
                    temp->next=new ListNode(1);
                    break;
                }
                l1->val+=1;
                if(l1->val>=10)
                    l1->val-=10;
                else
                    break;
                temp=l1;
                l1=l1->next;
            }
        }
        return head;
    }
};

//Solution 2
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode result(0);
        ListNode* head=&result;
        
        int carry=0;
        while(l1 || l2 || carry)
        {
            if(l1)
            {
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                carry+=l2->val;
                l2=l2->next;
            }
            head->next=new ListNode(carry%10);
            carry/=10;
            head=head->next;
        }
        return result.next;
    }
};
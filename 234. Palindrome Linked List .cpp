/*Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?*/

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
    bool isPalindrome(ListNode* head) 
    {
        if((head==NULL) || (head->next==NULL))
            return true;
        vector<int> vi;
        while(head)
        {
            vi.push_back(head->val);
            head=head->next;
        }
        int j=vi.size()-1;
        for(int i=0;i<j;i++,j--)
        {
            if(vi[i]!=vi[j])
                return false;
        }
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if((head==NULL) || (head->next==NULL))
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* half=slow->next;
        slow->next=NULL;
        half=reverseList(half);
        while(head && half)
        {
            if(head->val!=half->val)
                return false;
            head=head->next;
            half=half->next;
        }
        return true;
    }
    
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

//Solution 3

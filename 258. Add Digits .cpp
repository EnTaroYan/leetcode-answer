/* Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. 
For example: 
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 
Follow up:
Could you do it without any loop/recursion in O(1) runtime?  */

 
//Solution 1
class Solution {
public:
    int addDigits(int num) 
    {
        while(num>=10)
        {
            int temp=num;
            num=0;
            for(auto c:to_string(temp))
                num+=c-'0';
        }
        return num;
    }
};

//Solution 2   (Digital Root!!!)
class Solution {
public:
    int addDigits(int num) 
    {
        int temp=num%9;
        return ((temp==0) && num!=0) ?9:temp;
    }
};
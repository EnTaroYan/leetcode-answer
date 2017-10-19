/* Given an integer, write a function to determine if it is a power of three. 
Follow up:
Could you do it without using any loop / recursion?   */

//Solution 1
class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if(n==0)
            return false;
        while(n%3==0)
            n/=3;
        return n==1;
    }
};

//Solution 2

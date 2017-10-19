/* Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.   */

//Solution 1
class Solution {
public:
    int getSum(int a, int b) 
    {
        int sum=a;
        while(b)
        {
            sum=a^b;
            b=(a&b)<<1;
            a=sum;
        }
        return a;
    }
};
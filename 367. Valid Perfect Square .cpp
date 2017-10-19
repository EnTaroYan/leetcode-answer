/* Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt. 
Example 1: 
Input: 16
Returns: True

Example 2: 
Input: 14
Returns: False  */

//Solution 1
class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        int a=Q_rsqrt(num);
        return a*a==num;
    }
    
    inline float Q_rsqrt(float number)
    {
        float xhalf = 0.5f*number;
        int i = *(int *)&number;
        i = 0x5f375a86 - (i >> 1);
        number = *(float*)&i;
        number *= 1.5f - xhalf*number*number;
        number *= 1.5f - xhalf*number*number;
        //number *= 1.5f - xhalf*number*number;
        return 1/number;
    }
};
/* Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231). 
Example 1: 
Input:
3

Output:
3

Example 2: 
Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10. */

//Solution 1
class Solution 
{
public:
    int findNthDigit(int n) 
    {
        int index=1;
        for(int i=0;;++i,++index)
        {
            if(n>9*index*pow(10,i))
                n-=9*index*pow(10,i);
            else
                break;
        }
        int mod=n%index;
        if(mod==0)
        {
            n/=index;
            mod=index;
        }
        else
            n=n/index+1;
        n=pow(10,index-1)+n-1;
        n/=pow(10,index-mod);
        return n%10;
    }
};

//Solution 2

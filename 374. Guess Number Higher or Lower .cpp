/* We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.   */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

//Solution 1
class Solution {
public:
    int guessNumber(int n) 
    {
        int begin=1;
        int end=n;
        while(1)
        {
            int temp=guess(begin+(end-begin)/2);  // Do NOT use (begin+end)/2 in case of over flow!!!
            if(temp==-1)
                end=begin+(end-begin)/2-1;
            else if(temp==1)
                begin=begin+(end-begin)/2+1;
            else
                return begin+(end-begin)/2;
        }
    }
};
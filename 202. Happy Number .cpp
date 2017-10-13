/*Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1*/

//Solution 1
class Solution {
public:
    bool isHappy(int n) 
    {
        vector<int> ss;
		int sum=0;
        while(n>1)
        {
			ss.push_back(n);
			while(n)
			{
				sum+=pow(n%10,2);
				n/=10;
			}
            if(find(ss.begin(),ss.end(),sum)!=ss.end())
                return false;
			n=sum;
			sum=0;
        }
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool isHappy(int n) 
    {
		int sum=0;
        while(n>1)
        {
			while(n)
			{
				sum+=pow(n%10,2);
				n/=10;
			}
            if(sum==4)
                return false;
			n=sum;
			sum=0;
        }
        return true;
    }
};
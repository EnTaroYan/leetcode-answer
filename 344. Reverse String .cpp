/* Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".     */

//Solution 1
class Solution 
{
public:
    string reverseString(string s) 
    {
        for(auto iter1=s.begin(),iter2=s.end()-1;iter1<iter2;++iter1,--iter2)
            swap(*iter1,*iter2);
        return s;
    }
};

//Solution 2
class Solution 
{
public:
    string reverseString(string s) 
    {
       reverse(s.begin(),s.end());
        return s;
    }
};
/* Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle". 
Example 2:
Given s = "leetcode", return "leotcede". 
Note:
The vowels does not include the letter "y".      */

//Solution 1
class Solution 
{
public:
    string reverseVowels(string s) 
    {
        string v="aoiueAOUIE";
        for(auto iter1=s.begin(),iter2=s.end()-1;iter1<iter2;)
        {
            auto i1=find(v.begin(),v.end(),*iter1);
            auto i2=find(v.begin(),v.end(),*iter2);
            if(i1==v.end())
                ++iter1;
            if(i2==v.end())
                --iter2;
            if(i1!=v.end() && i2!=v.end())
            {
                swap(*iter1,*iter2);
                ++iter1;
                --iter2;
            }
        }
        return s;
    }
};
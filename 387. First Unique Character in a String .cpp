/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1. 
Examples: 
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.  */

//Solution 1
class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        vector<int> list(26,0);
        for(auto ch:s)
            ++list[ch-'a'];
        for(int i=0;i!=s.size();++i)
        {
            if(list[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};

//Solution 2

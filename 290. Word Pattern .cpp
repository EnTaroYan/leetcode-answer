/* Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.    */

//Solution 1
class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        map<char,string> list;
        map<string,char> list1;
        stringstream ss;
        ss<<str;
        int i=0;
        for(string s;ss>>s;++i)
        {
            if(list.find(pattern[i])==list.end())
            {
                list[pattern[i]]=s;
                if(list1.find(s)!=list1.end())
                    return false;
                list1[s]=pattern[i];
            }
            else
            {
                if(list[pattern[i]]!=s)
                        return false;
            }
        }
        return i==pattern.size();
    }
};
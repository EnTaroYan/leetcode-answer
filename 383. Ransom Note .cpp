/* Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false. 
Each letter in the magazine string can only be used once in your ransom note. 
Note:
You may assume that both strings contain only lowercase letters. 
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true  */

//Solution 1
class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int> list;
        for(auto ch:magazine)
            ++list[ch];
        for(auto ch:ransomNote)
        {
            if(list[ch]==0)
                return false;
            --list[ch];
        }
        return true;
    }
};

//Solution 2
class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> list(26,0);
        for(auto ch:magazine)
            ++list[ch-'a'];
        for(auto ch:ransomNote)
        {
            if(list[ch-'a'])
                --list[ch-'a'];
            else
                return false;
        }
        return true;
    }
};

//Solution 3
class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> list(26,0);
        for(auto ch:magazine)
            ++list[ch-'a'];
        for(auto ch:ransomNote)
            --list[ch-'a'];
        for(int a:list)
            if(a<0)
                return false;
        return true;
    }
};
/* Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false. 
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case? */


//Solution 1
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        else
            return false;
    }
};

//Solution 2
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> a(26,0);
        for(auto& ch:s)
            a[ch-'a']+=1;
        for(auto& ch:t)
            a[ch-'a']-=1;
        for(auto i:a)
            if(i!=0)
                return false;
        return true;
    }
};



/* 部分回文

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length())
            return false;
        int len=s.length();
        int i=0,j=0;
        while(i<len)
        {
            if(s[i]!=t[i])
            {
                int temp_i=i;
                j=i;
                while(1)
                {
                    j=distance(t.begin(),find(t.begin()+j,t.end(),s[temp_i]));
                    if(j>=len)
                        return false;
                    int temp=j;
                    while(i<=temp)
                    {
                        if(s[i]!=t[j])
                            break;
                        ++i;
                        --j;
                    }
                    if(i==temp+1)
                    {
                        i=temp;
                        break;
                    }
                    else
                    {
                        i=temp_i;
                        j=temp+1;
                        if(j>=len)
                            return false;
                    }
                }
            }
            ++i;
        }
        return true;
    }
}; */
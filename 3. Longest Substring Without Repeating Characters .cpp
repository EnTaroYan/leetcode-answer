/* Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring. */


 
//Solution 1      //leetcode can not access but vs2015 is ok!!!
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> list;
        int max = 0;
        for (auto ch : s)
        {
            ++list[ch];
            if (list[ch] > 1)
            {
                list.erase(list.begin(), list.find(ch));
                list[ch] = 1;
            }
            int num = list.size();
            if (num > max)
                max = num;
        }
        return max;
    }
};

//Solution 2

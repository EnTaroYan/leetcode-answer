/*Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. */


//Solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if(nums.empty())
            return false;
        sort(nums.begin(),nums.end());
        for(auto iter=nums.begin()+1;iter!=nums.end();iter++)
        {
            if(*iter==*(iter-1))
                return true;
        }
        return false;
    }
};
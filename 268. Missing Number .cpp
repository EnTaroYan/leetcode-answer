/* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array. 
For example,
Given nums = [0, 1, 3] return 2. 
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?   */

 
//Solution 1
 class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i!=nums.size();++i)
        {
            if(nums[i]!=i)
                return i;
        }
        return*(nums.end()-1)+1;
    }
};


//Solution 2
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum1=nums.size(),sum2=0;
        for(int i=0;i!=nums.size();++i)
        {
            sum1+=i;
            sum2+=nums[i];
        }
        return sum1-sum2;
    }
};

//Solution 3
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int result=nums.size();
        for(int i=0;i!=nums.size();++i)
        {
            result^=nums[i];
            result^=i;
        }
        return result;
    }
};
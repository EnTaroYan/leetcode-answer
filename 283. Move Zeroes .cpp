/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.   */

//Solution 1
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int len=nums.size();
        for(int i=0;i!=len-1;++i)
        {
            if(nums[i]==0)
            {
                for(int j=i+1;;++j)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[i],nums[j]);
                        break;
                    }
                    if(j==len-1)
                        return;
                }
            }
        }
    }
};

//Solution 2
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        
        for(int lastzero=0, i=0;i<nums.size();++i)
            if(nums[i]!=0)
                swap(nums[lastzero++],nums[i]);
    }
};

//Solution 3
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int idx=0;
        int len=nums.size();
        for(int i=0;i<len;++i)
        {
            if(nums[i]!=0)
                nums[idx++]=nums[i];
        }
        while(idx<len)
            nums[idx++]=0;
    }
};
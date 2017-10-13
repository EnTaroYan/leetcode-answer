//Solution 1
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int len=nums.size();
        k%=len;
        if(k==0)
            return;
        vector<int> temp(nums);
        for(int i=0;i!=len;i++)
        {
            if(i-k>=0)
                nums[i]=temp[i-k];
            else
            {
                nums[i]=temp[len+i-k];
            }
        }
    }
};

//Solution 2
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        k%=nums.size();
        if(k==0)
            return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
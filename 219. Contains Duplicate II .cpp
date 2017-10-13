/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that 
nums[i] = nums[j] and the absolute difference between i and j is at most k.  */


//Solution 1   (my first accepted answer, very very very slow!!!)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int len=nums.size();
        if(len<=1 || k<=0)
            return false;
        vector<int> temp;
        if(len<=k+1)
            temp.insert(temp.begin(),nums.begin(),nums.end());
        else
            temp.insert(temp.begin(),nums.begin(),nums.begin()+k);
        if(containsDuplicate(temp))
            return true;
        for(int i=1;i<len-k;i++)
        {
            for(int j=i;j<=i+k-1;j++)
                if(nums[j]==nums[i+k])
                    return true;
        }
        return false;
    }
	
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(auto iter=nums.begin()+1;iter!=nums.end();iter++)
        {
            if(*iter==*(iter-1))
                return true;
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> list;
        for(int i=0;i!=nums.size();i++)
        {
            if(list.find(nums[i])==list.end())
                list[nums[i]]=i;
            else
            {
                if(i-list[nums[i]]<=k)
                    return true;
                else
                    list[nums[i]]=i;
            }
        }
        return false;
    }
};
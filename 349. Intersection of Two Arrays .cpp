/* Given two arrays, write a function to compute their intersection. 
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. 
Note:
Each element in the result must be unique.
The result can be in any order.     */

//Solution 1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto iter1=nums1.begin(),iter2=nums2.begin();iter1!=nums1.end() && iter2!=nums2.end();)
        {
            if(*iter1<*iter2)
                ++iter1;
            else if(*iter1>*iter2)
                ++iter2;
            else
            {
                result.push_back(*iter1);
                ++iter1;
                ++iter2;
            }
        }
        if(result.empty())
            return result;
        for(auto iter=result.begin()+1;iter!=result.end();++iter)
        {
            if(*iter==*(iter-1))
            {
                iter=result.erase(iter)-1;
            }
        }
        return result;
            
    }
};

//Solution 2

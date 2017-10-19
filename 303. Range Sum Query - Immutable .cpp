/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.   */

//Solution 1
class NumArray {
public:
    NumArray(vector<int> nums) 
    {
        data=nums;
    }
    
    int sumRange(int i, int j) 
    {
        int sum=0;
        for(;i<=j;++i)
            sum+=data[i];
        return sum;
    }
private:
    vector<int> data;
    
};

//Solution 2
class NumArray {
public:
	NumArray(vector<int> nums) : data(nums.size()+1, 0) {
		for (int i = 0; i < nums.size(); i++)
		{
			data[i + 1] = data[i] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		return data[j + 1] - data[i];
	}

private:
	vector<int> data;
};
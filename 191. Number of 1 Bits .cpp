/*Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.*/

//Solution 1
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        bitset<32> bin(n);
        return bin.count();
    }
};

//Solution 2
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int result=0;
        for(int i=0;i!=32;i++)
        {
            result+=(n & 1);
            n>>=1;
        }
        return result;
    }
};
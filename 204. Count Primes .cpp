/*Count the number of prime numbers less than a non-negative number, n.*/

//Solution 1
class Solution {
public:
    int countPrimes(int n) 
    {
        int result=1;
        vector<bool> prime(n,true);
        int upper=sqrt(n);
        if(n<=2)
            return 0;
        for(int i=3;i<n;i+=2)
        {
            if(prime[i]==false)continue;
                result++;
            if(i>upper)continue;
            for(int j=i*2;j<n;j+=i)
                prime[j]=false;
        }
        return result;
    }
};
//Solution 1
class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string result;
        string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int temp;
        while(n>0)
        {
            temp=n%26;
            n/=26;
            if(temp==0)
            {
                n-=1;
                temp=26;
            }
            result.push_back(alp[temp-1]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
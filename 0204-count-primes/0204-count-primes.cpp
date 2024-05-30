class Solution {
public:
    int countPrimes(int n) 
    {
        vector<int>prime(n+1,1);
        int range =sqrt(n);
        int count =0;
        for(int i =2;i<=range;i++)
        {
            if(prime[i])
            {
                count++;
                for(int j =i*i ;j<=n;j+= i)prime[j]=0;
            }
        }
        for(int i =range+1;i<n;i++)count += prime[i];
        return count;
    }
};
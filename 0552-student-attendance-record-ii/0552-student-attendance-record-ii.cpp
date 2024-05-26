class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int mod =1e9+7;
    int solver(int A,int L,int n,vector<vector<vector<int>>>&dp)
    {
        if(A>=2 || L >=3)return 0;
        if(!n)return 1;
        if(dp[A][L][n]!=-1)return dp[A][L][n];
        int present =solver(A,0,n-1,dp)%mod;
        int absent = solver(A+1,0,n-1,dp)%mod;
        int late =solver(A,L+1,n-1,dp)%mod;
        return dp[A][L][n]=((present+absent)%mod+late)%mod;
    }
    int checkRecord(int n) 
    {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(3,vector<int>(n+1,-1)));
        return solver(0,0,n,dp)%mod;
    }
};
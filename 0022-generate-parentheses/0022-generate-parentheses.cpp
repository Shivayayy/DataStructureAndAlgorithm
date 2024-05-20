class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void generator(vector<string>&sol,string &w,int open,int close)
    {
        if(!close)
        {
            sol.push_back(w);
            return;
        }
        if(open && open-1<close)
        {
            string temp =w;
            w = w+'(';
            generator(sol,w,open-1,close);
            w =temp;
        }
        if(close>open)
        {
            w = w+')';
            generator(sol,w,open,close-1);
        }  
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>sol;
        string w ="(";
        generator(sol,w,n-1,n);
        return sol;
    }
};
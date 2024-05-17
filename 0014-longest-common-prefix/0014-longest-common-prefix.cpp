class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans ="";
        int n =INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            int len =strs[i].size();
            n =min(n,len);
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
            char c =strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(c!=strs[j][i])return ans;
            }
            ans+= c;
        }
        return ans;
    }
};
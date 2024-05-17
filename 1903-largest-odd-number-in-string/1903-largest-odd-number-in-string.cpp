class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string largestOddNumber(string s) 
    {
        int i =s.size();
        while(i>=0)
        {
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9') break;
            i--;
        }
        return i>=0?s.substr(0,i+1):"";
    }
};
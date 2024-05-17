class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int>map(26,0);
        for(int i=0;i<s.size();i++)map[s[i]-'a']++;
        for(int j=0;j<t.size();j++)map[t[j]-'a']--;
        for(int i=0;i<26;i++)if(map[i])return false;
        return true;
    }
};
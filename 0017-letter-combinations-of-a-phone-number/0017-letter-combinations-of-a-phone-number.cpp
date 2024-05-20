class Solution {
public:
    void helper(string digits,int index,string opt,vector<string>&ans,unordered_map<int,string>&mp)
    {
        if(index == digits.size())
        {
            ans.push_back(opt);
            return;
        }
        int digit =digits[index]-'0';
        string digform =mp[digit];
        for(auto it:digform)
        {
            string posib =opt+it;
            helper(digits,index+1,posib,ans,mp);
        }

    }
    vector<string> letterCombinations(string digits) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<string>ans;
        if(!digits.size())return ans;
        // vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        helper(digits,0,"",ans,mp);
        return ans;

    }
};
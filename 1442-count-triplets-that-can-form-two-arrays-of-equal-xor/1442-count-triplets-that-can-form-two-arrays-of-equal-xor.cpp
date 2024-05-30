class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int countTriplets(vector<int>& arr) 
    {
        
        int xorer =0;
        unordered_map<int,vector<int>>mp;
        mp[0].push_back(-1);
        int ans =0;
        for(int i =0;i<arr.size();i++)
        {
            xorer =xorer^arr[i];
            if(mp.find(xorer)!=mp.end())
            {
                vector<int>vec =mp[xorer];
                for(int j:vec)ans =ans+(i-j-1);
            }
            mp[xorer].push_back(i);
        }
        return ans;
    }
};
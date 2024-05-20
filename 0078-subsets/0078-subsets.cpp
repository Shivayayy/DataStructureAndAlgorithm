class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n =nums.size();
        for(int mask=0;mask<(1<<n);mask++)
        {
            vector<int>s;
            for(int i=0;i<n;i++)
            {
                if(mask & 1<<i)s.push_back(nums[i]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};
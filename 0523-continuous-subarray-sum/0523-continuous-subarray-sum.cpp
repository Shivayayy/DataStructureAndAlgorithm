class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(i &&sum%k == 0 )return true;
            int mod =sum%k;
            if(mp.find(mod)!=mp.end())
            {
                if(i-mp[mod]>=2)return true;
            }
            else mp[mod]=i;
        }
        return false;
    }
};
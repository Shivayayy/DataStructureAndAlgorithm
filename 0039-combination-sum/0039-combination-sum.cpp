class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void combinator(vector<int>& candidates,int target,vector<vector<int>>&sols, vector<int>&sol,int i)
    {
        if(i == candidates.size())
        {
            if(!target)sols.push_back(sol);
            return;
        }
        combinator(candidates,target,sols,sol,i+1);

        if(target-candidates[i]>=0)
        {
            sol.push_back(candidates[i]);
            combinator(candidates,target-candidates[i],sols,sol,i);
            sol.pop_back();
        }   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>sol;
        vector<vector<int>>sols;
        combinator(candidates,target,sols,sol,0);
        return sols;
    }
};
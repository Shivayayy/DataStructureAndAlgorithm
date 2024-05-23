class Solution {
public:
    void func(vector<int> &nums,int &k,int ind,vector<int> &temp,int &ans)
    {
        if(ind<0){
            ans++;
            return;
        }
        func(nums,k,ind-1,temp,ans);//not pick
        int n1=temp.size();
        int flag=0;
        for(int i=0;i<n1;i++)
        {
            if(abs(nums[ind]-temp[i])==k){
                flag=1;
                break;
            }
        }
        if(!flag) {
            temp.push_back(nums[ind]);
            func(nums,k,ind-1,temp,ans);

            temp.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int ans=0;
        func(nums,k,n-1,temp,ans);
        return ans-1;
    }
};
class Solution {
public:
    int greaterOrEqual(vector<int>&nums,int k)
    {
        int count =0;
        for(int i=0;i<nums.size();i++)if(nums[i]>=k)count++;
        return count;
    }
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int low =0;
        int high =INT_MIN;
        for(int i=0;i<nums.size();i++)high =max(high,nums[i]);
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            int numGreater =greaterOrEqual(nums,mid);
            if(mid == numGreater)return mid;
            else if(mid<numGreater)low =mid+1;
            else high =mid-1;
        }
        return -1;
    }
};
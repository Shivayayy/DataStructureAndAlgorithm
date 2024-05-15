class Solution {
public:
    bool afterDivision(vector<int>&nums,int threshold,int k)
    {
        int divisor =0;
        for(int i=0;i<nums.size();i++) divisor +=ceil((double)nums[i]/(double)k);
        return divisor>threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low =1;
        int high =INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            high =max(high,nums[i]);
        }
        while(low<=high)
        {
            int mid =low+(high-low)/2;
            if(afterDivision(nums,threshold,mid))low =mid+1;
            else high =mid-1;
        }
        return low;
    }
};
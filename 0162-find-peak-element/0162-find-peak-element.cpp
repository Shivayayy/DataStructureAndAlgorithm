class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size() == 1)return 0;
        if(nums[1]<nums[0])return 0;
        if(nums[nums.size()-2]<nums[nums.size()-1])return nums.size()-1;
        int low =1;
        int high =nums.size()-2;
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid])return mid;
            else if(nums[mid-1]<nums[mid])low =mid+1;
            else high =mid-1;
        }
        return -1;
    }
};
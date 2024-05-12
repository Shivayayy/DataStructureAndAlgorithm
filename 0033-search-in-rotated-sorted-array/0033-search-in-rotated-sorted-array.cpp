class Solution {
public:
    int search(vector<int>& arr, int target) 
    {
        int low =0;
        int high =arr.size()-1;
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            if(arr[mid]==target)return mid;
            //left half
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=target && target<=arr[mid])high=mid-1;//stay in left half
                else low =mid+1;//move to the right half
            }
            else
            {
                if(arr[mid]<=target && target<=arr[high])low =mid+1;
                else high =mid-1;
            }
        }
        return -1;

    }
};
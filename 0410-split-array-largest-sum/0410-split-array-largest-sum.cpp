class Solution {
public:
    int canAllocate(vector<int>& arr,int bookPage)
    {
        int students =1;
        long long sum =0;
        for(auto it :arr)
        {
            if(it+sum<=bookPage)
            {
                sum += it;
            }
            else
            {
                students++;
                sum =it;
            }
        }
        return students;
    }
    int splitArray(vector<int>& arr, int m) {
        if(arr.size()<m)return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            int currPages =canAllocate(arr,mid);
            if(currPages<=m)high =mid-1;
            else low =mid+1;
        }
        return low;
    }
};
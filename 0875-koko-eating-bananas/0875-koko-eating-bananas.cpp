class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    double numHour(vector<int>&piles ,int k)
    {
        double hours =0;
        for(int i=0;i<piles.size();i++)
        {
            hours += ceil(double(piles[i])/double(k));
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int high =INT_MIN;
        for(int &it :piles)high =max(high,it);
        int low =1;
        while(low<=high)
        {
            int mid =low+(high-low)/2;
            double midHours =numHour(piles,mid);
            if(midHours >h)low =mid+1;
            else high =mid-1;
        }
        return low;
        
    }
};
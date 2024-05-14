class Solution {
public:
    int boquetsMade(vector<int>& bloomDay,int day,int k,int m)
    {
        
        int consDays =0;
        int ans =0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)consDays++;
            else
            {
                ans += consDays/k;
                consDays =0;
            }
        }
        ans += consDays/k;
        return ans<m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low =INT_MAX;
        int high =INT_MIN;
        for(int  &it :bloomDay)
        {
            low =min(low,it);
            high=max(high,it);
        }
        int maxi =high;
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            if(boquetsMade(bloomDay,mid,k,m))low =mid+1;
            else high =mid-1;
        }
        if(low>maxi)return -1;
        return low;
    }
};
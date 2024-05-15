class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int fun(vector<int>&position,int m ,int k)
    {
        int balls =1;
        int last =0;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[last]>=k)
            {
                balls++;
                last =i;
            }
        }
        return balls<m;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(),position.end());
        int low =1;
        int high =position[position.size()-1]-position[0];
        while(low<=high)
        {
            int mid =low +(high-low)/2;
            if(fun(position,m,mid))high =mid-1;
            else low =mid+1;
        }
        return high;
    }
};
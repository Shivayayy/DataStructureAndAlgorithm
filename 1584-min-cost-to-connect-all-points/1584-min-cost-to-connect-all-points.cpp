class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(points.size(),0);
        pq.push({0,0});
        int sum =0;

        while(!pq.empty())
        {
            int weight =pq.top().first;
            int j =pq.top().second;
            int x =points[j][0];
            int y =points[j][1];
            pq.pop();

            if(vis[j])continue;

            vis[j] =1;
            sum += weight;

            for(int i=0;i<points.size();i++)
            {
                if(i!=j && !vis[i])
                {
                    int weight =abs(x-points[i][0])+abs(y-points[i][1]);
                    pq.push({weight,i});
                } 
            }
        }
        return sum;
    }
};
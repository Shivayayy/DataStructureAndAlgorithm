class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) 
    {
         if(nums.size()%k !=0)return false;
        multiset<int>ms;
        for(int i=0;i<nums.size();i++)ms.insert(nums[i]);

        multiset<int, greater<int> >::iterator itr;
        for (itr = ms.begin(); itr != ms.end(); ++itr) 
        {
            int num =*itr;
            for(int j=1;j<k;j++)
            {
                if(ms.find(num+j)!=ms.end())ms.erase(ms.find(num+j));
                else return false;
            }
        }
        return true;
    }
};
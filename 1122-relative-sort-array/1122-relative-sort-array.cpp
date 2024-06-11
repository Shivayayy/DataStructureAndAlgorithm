class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int,int>mp;
        for(int i =0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])==mp.end())mp[arr2[i]]=i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            
            if(mp.find(a)!=mp.end())
            {
                if(mp.find(b)!=mp.end())return mp[a]<mp[b];
                else return true;
            }
            else if(mp.find(b)!=mp.end())return false;
            return a<b;
        });
        return arr1;
    }
};
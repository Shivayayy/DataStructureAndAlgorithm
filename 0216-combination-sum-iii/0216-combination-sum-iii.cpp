
class Solution {
public:
    void findsum(int k, int n, int a, vector<int>&v, vector<vector<int>>&vv){
        if(n==0 && k==0){
            vv.push_back(v);
            return;
        }
        for(int i=a; i<=9 && n-i>=0 && k>0; ++i){
            v.push_back(i);
            findsum(k-1,n-i,i+1,v,vv);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vv;
        if(k>n || n>45) return {};
        vector<int> v;
        findsum(k,n,1,v,vv);
        return vv;
    }
};
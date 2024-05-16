class Solution {
public:
    int maxRow (vector<vector<int>>& mat,int column)
    {
        int maxi =INT_MIN;
        int index =-1;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][column]>maxi)
            {
                maxi =mat[i][column];
                index =i;
            }       
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int low =0;
        int high =mat[0].size()-1;
        while(low<=high)
        {
            int mid =low+(high-low)/2;
            int row =maxRow(mat,mid);
            int right =mid+1<mat[0].size()?mat[row][mid+1]:-1;
            int left =mid-1>=0?mat[row][mid-1]:-1;
            if(mat[row][mid]>right && mat[row][mid]>left)return {row,mid};
            else if(mat[row][mid]<left)high =mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n =matrix.size();
        int m =matrix[0].size();
        int row =0;
        int column =m-1;
        while(row<n&&column>=0)
        {
            int value =matrix[row][column];
            if(value == target)return true;
            else if(value<target)row++;
            else column--;
        }
        return false;
    }
};
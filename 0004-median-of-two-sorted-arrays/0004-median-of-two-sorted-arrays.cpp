class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 =nums1.size();
        int n2 =nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
        int low =0;
        int high =n1;
        int n =n1+n2;
        int left =(n1+n2+1)/2;
        while(low<=high)
        {
            int midOne =low +(high-low)/2;
            int midTwo =left -midOne;
            int leftOne =INT_MIN;
            int leftTwo =INT_MIN;
            int rightOne =INT_MAX;
            int rightTwo =INT_MAX;
            if(midOne<n1)rightOne =nums1[midOne];
            if(midTwo<n2)rightTwo =nums2[midTwo];
            if(midOne-1>=0)leftOne =nums1[midOne-1];
            if(midTwo-1>=0)leftTwo =nums2[midTwo-1];
            if(leftOne<=rightTwo && leftTwo <=rightOne)
            {
                if(!(n&1))return ((double)(max(leftOne,leftTwo)+min(rightOne,rightTwo)))/2.0;
                else return double(max(leftOne,leftTwo));
            }
            else if(leftOne>rightTwo)high =midOne-1;
            else low =midOne+1;
            
        }
        return 0.0;
    }
};
class Solution {
public:
    double power(double x,int n)
    {
        if(!n)return 1;
        if(n ==1)return x;
        double h = power(x,n/2);
        if(n&1)return x*h*h;
        return h*h;
    }
    double myPow(double x, int n) 
    {
        if(n == INT_MIN)return 1/x *1/power(x,-(n+1));
        return n<0?1/power( x,-n):power(x,n);
    }
};
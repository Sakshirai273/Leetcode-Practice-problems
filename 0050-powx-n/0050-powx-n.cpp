class Solution {
public:
    double fun(double x,int n)
    {
        if(n==1)
            return x;
        if(n==0)
            return 1;

        double res=fun(x,n/2);
        if(n%2==0)
            return res*res;
        else
            return x*res*res;
    }
    double myPow(double x, int n) {
        if(n==0)
            return 1;

        if(n>0)
            return fun(x,n);
        else
            return 1/fun(x,n);
    }
};
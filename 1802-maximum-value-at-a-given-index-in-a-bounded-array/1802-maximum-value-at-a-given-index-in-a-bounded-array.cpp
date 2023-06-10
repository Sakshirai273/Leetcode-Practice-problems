class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int lo=1;
        int hi=maxSum;
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(n,index,maxSum,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
    bool check(int n,int idx,long long maxsum,int mid){
        long long left=0;
        long long right=0;
        int leftrange=idx;
        int rightrange=n-idx-1;
                   //         left
        if(mid-1>leftrange){
            left=sum(mid-1)-sum(mid-1-leftrange);
        }
        else
        {
            left=sum(mid-1)+(leftrange-mid+1);
        }
                   //         right
        if(mid-1>rightrange){
            right=sum(mid-1)-sum(mid-1-rightrange);
        }else{
            right=sum(mid-1)+(rightrange-mid+1);
        }
        if(left+right+mid<=maxsum)
            return true;
        return false;
    }
    long long sum(long long n){
        long long sum=(n*(n+1))/2;
        return sum;
    }
};
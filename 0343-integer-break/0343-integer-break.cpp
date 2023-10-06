class Solution {
public:
    int dp[59][2];
    int integerBreak(int n) {   
        memset(dp,-1,sizeof dp);
        return f(n,false);
    }
    
    int f(int n,bool possible){
        if(dp[n][possible]!=-1)
            return dp[n][possible];
        int maxpro=1;
        if(possible)
            maxpro=n;
        for(int i=1;i<n;i++){
            maxpro=max(maxpro,i*f(n-i,true));
        }
        return dp[n][possible] = maxpro;
    }
};
    
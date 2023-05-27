class Solution {
public:
    vector<int>dp;
    bool winnerSquareGame(int n) {
        
      //  0 -> false
        //    1 -> true
            dp.resize(n+1 , -1);
       return solve(n , dp);
    }
    int solve(int n ,vector<int> & dp){
        if(n==0)
            return false;
        if(dp[n] != -1)
            return dp[n];
        for(int i = 1; i*i <= n ; i++){
            if( solve(n- i*i , dp) == false )
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }
};
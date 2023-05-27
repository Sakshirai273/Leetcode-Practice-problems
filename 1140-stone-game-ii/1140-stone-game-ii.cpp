class Solution {
public:
    int dp[101][201];
    int help(int i , int M , vector<int>&p)
    {
        if( i >= p.size())
            return 0 ;
        if(dp[i][M] != -1)
            return dp[i][M];
        int total = 0;
        int ans = INT_MIN;      
            for(int j= 0 ; j <2*M;j++) {//j+1 is the total no . of stones we are picking
                if( i+j < p.size())
                    total += p[i+j];
                ans= max(ans , total - help(i+j+1 , max(M,j+1),p))   ;
    }
        return dp[i][M]= ans;
    }
    int stoneGameII(vector<int>& p) {
        int sum = 0 ; 
        memset(dp , -1 , sizeof dp);
        for(auto a:p)
            sum += a;
        int diff = help(0, 1 , p);
        return (sum + diff)/2;
    }
};
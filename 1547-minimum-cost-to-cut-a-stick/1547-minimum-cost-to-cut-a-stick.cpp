class Solution {
public:
    int dp[102][102]; // because we have push backed 2 variabes  0 ,n  already
    int solve(int l , int r , vector<int>&cuts){
        if(r - l == 1)
            return 0;
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int cost = INT_MAX;
        for(int i = l +1 ; i<r ; i++){
            cost = min(cost , cuts[r] - cuts[l] + solve(l ,  i , cuts) + solve (i , r, cuts)); ///length of curr stick + left part + right part
        }
            return dp[l][r] = cost == INT_MAX ?0 : cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp , -1 , sizeof(dp));
        cuts.push_back(0); //left end of the stick
        cuts.push_back(n); // right end of the stick
        sort(cuts.begin() , cuts.end());
        
        return solve(0 , cuts.size()-1, cuts);
    }
};
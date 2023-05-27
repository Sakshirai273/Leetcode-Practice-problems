class Solution {
public:
    int dp[501][501];
    int helpf(int i , int j , vector<int> &piles){
        if(i>j) // no stone remaining
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(piles[i] - helpf (i+1 , j , piles) , piles[j] - helpf(i, j-1, piles)); // pick either first from left or first from right side 
    }
    
    bool stoneGame(vector<int>& piles) {
    int n = piles.size();
        memset(dp , -1 , sizeof dp);
        return helpf( 0 , n-1 ,piles) > 0;
    }
};
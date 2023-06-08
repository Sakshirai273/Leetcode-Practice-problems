class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = n-1 ;
        int col = 0 ;
        int cnt  = 0;
        while(row >= 0 && col < m ){
            if(grid[row][col] < 0){
                --row;
                cnt += m- col;
            }
            else{
                ++col;
            }
        }
    return cnt;
}
};
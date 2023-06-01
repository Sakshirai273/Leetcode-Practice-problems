class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = m - 1;
        std::queue<int> q;
        q.push(0);
        if (grid[0][0] == 1 || grid[n][n] == 1) return -1;
        grid[0][0] = 1;
        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            int i = curr & (1 << 7) - 1, j = curr >> 7;
            if (i == n && j == n) return grid[n][n];
            for (int a = std::max(i-1,0); a <= std::min(i+1,n); a++)
                for (int b = std::max(j-1,0); b <= std::min(j+1,n); b++)
                    if (grid[a][b] == 0) {
                        grid[a][b] = grid[i][j] + 1;
                        q.push(a + (b << 7));
                    }
        }
        return -1;
    }
};
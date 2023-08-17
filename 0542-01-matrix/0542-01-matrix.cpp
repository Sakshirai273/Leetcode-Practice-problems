class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int n = mat.size();
     int m = mat[0].size();
     int l[4] = {-1,0,1,0};   
     int p [4]= {0,1,0,-1};
     queue<pair<int,int>> q;
     vector<vector<int>> ans(n,vector<int>(m,-1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j] == 0){
                q.push({i,j});
                ans[i][j] = 0;
            }
        }
    }
    int count =0;
    while(!q.empty()){
        int k = q.size();
        count++;
        for(int i = 0;i<k;i++){
            pair<int,int> node  = q.front();
            q.pop();
            for(int j = 0;j<4;j++){
                int row = node.first + l[j];
                int col = node.second + p[j];
                if(row >=0 && row <n && col >=0 && col < m && ans[row][col] == -1 && mat[row][col] == 1)    {
                    q.push({row,col});
                    ans[row][col] = count;
                }
            }
        }
    }
    return ans;
    }
};

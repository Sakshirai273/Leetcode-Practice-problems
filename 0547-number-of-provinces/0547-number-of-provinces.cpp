class Solution {
public:
    void dfs ( unordered_map<int,vector<int>> &adj, int u , vector<bool> &vis ){
        vis[u] = true;
        for(int &v : adj[u]){
            if(!vis[v])
            dfs(adj, v, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n =  isConnected.size();  
        //make graph
        unordered_map<int,vector<int>>adj;
        
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
           vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0 ; i <n ;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj , i , vis);
            }
        }
        return cnt;
    }
};
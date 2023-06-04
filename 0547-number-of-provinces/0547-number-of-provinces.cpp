class Solution {
public:
    int n ;
    void bfs (vector<vector<int>> &isConnected, int u , vector<bool> &vis ){
        queue<int>q;
        q.push(u);
        vis[u] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int v =0 ; v<n ;v++){
                if(!vis[v] && isConnected[u][v] ==1)
                    bfs(isConnected,v,vis);
            }
        }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
      n =  isConnected.size();  
           vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0 ; i <n ;i++){
            if(!vis[i]){
                   bfs(isConnected , i , vis);
                cnt++;
             
            }
        }
        return cnt;
    }
};
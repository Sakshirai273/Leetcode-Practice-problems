class Solution {
public:
    
    bool check(long long x1, long long y1, long long x2, long long y2, long long d) {
        long long x = (x1-x2) * (x1-x2);
        long long y = (y1-y2) * (y1-y2);
        
        return (x + y  <= d * d);
    }

    int detonate(vector<vector<int>>& adj, vector<bool>& vis, int node, int n) {
        
        int count = 1;
        vis[node] = true;
        
        for(auto& adjnode : adj[node]) {
            if(!vis[adjnode]) {
                count += detonate(adj, vis, adjnode, n);
            }
        }
        
        return count;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        
        int maxBombs = 0;
        vector<vector<int>> deto_adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                    deto_adj[i].push_back(j);
                }  
            }
        }
        for(int i=0; i<n; i++) {
            vector<bool> vis(n, false);

            maxBombs = max(maxBombs, detonate(deto_adj, vis, i, n));
        }
        
        return maxBombs;
    }
};
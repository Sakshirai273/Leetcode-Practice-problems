class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> g(n,vector<int>(0));
        for(int i=0;i<n;i++){
            if(i==headID)continue;
            // g[i].push_back(manager[i]);
            g[manager[i]].push_back(i);
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<i<<"-->";
        //     for(int j:g[i])cout<<j<<" ";
        //     cout<<endl;
        // }
        
        int ans=0;
        queue<pair<int,int>> q;
        q.push({headID,0});
        vector<int> vis(n,0);
        vis[headID]=1;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            
            ans=max(ans,time);
            
            for(int i=0;i<g[node].size();i++){
                if(vis[g[node][i]]==0){
                    q.push({g[node][i],time+informTime[node]});
                    vis[g[node][i]]=1;
                }
            }
        }
        return ans;
    }
};
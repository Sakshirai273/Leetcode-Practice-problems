//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        vector<bool>vis;
  vector<bool>dp;
  bool solve(int node,vector<int> adj[])
  {
      if(dp[node])
      {
          return true;
          }
      if(vis[node])
      {
          return false;
      }
      vis[node]=true;
      bool ans=true;
      
      for(auto itr:adj[node])
      {
          ans=ans&solve(itr,adj);
      }
     
      return dp[node]=ans;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
    vis.assign(V,false);
    dp.assign(V,false);
      for(int i=0;i<V;i++)
      {  if(!vis[i]){
          solve(i,adj);
      }
      }
      vector<int>res;
      for(int i=0;i<V;i++)
      {
          if(dp[i])
          {
              res.push_back(i);
          }
      }
      return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
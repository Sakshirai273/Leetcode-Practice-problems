class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> req(graph.size());
        vector<vector<int>> revg(graph.size());
        for(int i=0;i<graph.size();i++){
            req[i]=graph[i].size();

            for(int &j:graph[i]){
                revg[j].push_back(i);
            }
        }
    
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<req.size();i++){
            if(req[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            for(int &i:revg[temp]){
                req[i]--;
                if(req[i]==0)q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
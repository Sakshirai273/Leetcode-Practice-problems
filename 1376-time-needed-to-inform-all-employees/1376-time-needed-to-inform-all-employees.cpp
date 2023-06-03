class Solution {
public:
    int maxTime= 0;
  void BFS(unordered_map<int , vector<int>> &adj , vector<int> & informTime , int headID ){
      queue<pair<int, int>> q;
      q.push({headID, 0});
      
      while(!q.empty()){
          pair<int, int> temp = q.front();
          q.pop();
          int curr_employee = temp.first;
          int curr_time = temp.second;
          maxTime = max(maxTime , curr_time );
          for(int &employee : adj[curr_employee]){
              q.push({employee, curr_time + informTime[curr_employee]});
              // time at which 'v' will receive the info
          }
      }
  }
    void DFS(unordered_map<int , vector<int>> &adj , vector<int> & informTime , int curr_employee , int curr_time ){
        maxTime= max(maxTime, curr_time);
        for(int &employee : adj[curr_employee]){
            DFS(adj, informTime, employee , curr_time + informTime[curr_employee]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int , vector<int>>adj;
        for(int i = 0 ; i< manager.size(); i++){
            int employee_i = i ;
            int manager_i = manager[i];
            
            if(manager_i != -1)
                adj[manager_i].push_back(employee_i);
        }
              //DFS(adj , informTime , headID ,0 );
        BFS(adj , informTime , headID );
            return maxTime;
        }
    };
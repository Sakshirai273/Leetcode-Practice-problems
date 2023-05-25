//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int ind,string s,int target,vector<string> &res,string tmp,long long prev,long long sum){
      if(ind==s.size()){
          if(sum==target)
            res.push_back(tmp);
          return;
      }
      string st="";
      long long curr=0;
      for(int i=ind;i<s.size();i++){

          if(i>ind && s[ind]=='0')
            break;
        
          st+=s[i];
          
          curr=stoll(st);
          if(ind==0)
          solve(i+1,s,target,res,tmp+st,curr,curr);
          else{
              solve(i+1,s,target,res,tmp+"+"+st,curr,sum+curr);
              solve(i+1,s,target,res,tmp+"-"+st,-curr,sum-curr);
              
              solve(i+1,s,target,res,tmp+"*"+st,prev*curr,sum-prev+prev*curr);
          }
      }
      return;
  }
    vector<string> addOperators(string s, int target) {
        vector<string> res;
        string tmp="";
        long long prev=0;
        solve(0,s,target,res,tmp,prev,0);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
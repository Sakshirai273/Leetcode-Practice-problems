//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
        vector<string>ans;
        
    void helper(string &s,string temp,int vis[],int n){
        if(temp.length()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                temp.push_back(s[i]);
                vis[i]=1;
                helper(s,temp,vis,n);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        int n=s.length();
        int vis[n];
        for(int i=0;i<n;i++)vis[i]=0;
        helper(s,"",vis,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
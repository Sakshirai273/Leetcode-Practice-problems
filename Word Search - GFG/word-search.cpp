//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
       vector<vector<bool>> vis;
    bool fun(vector<vector<char>>&board,int i,int j,int m,int n,string word,int l){
        if(l==word.length()){
            return true;
        }
        if(i<0 || j<0 || i==m || j==n || word[l]!=board[i][j] || vis[i][j]){
            return false;
        }
        vis[i][j]=true;
        bool left,right,up,down;
        left=fun(board,i,j-1,m,n,word,l+1);
        right=fun(board,i,j+1,m,n,word,l+1);
        up=fun(board,i-1,j,m,n,word,l+1);
        down=fun(board,i+1,j,m,n,word,l+1);
        vis[i][j]=false;
        return left||right||up||down;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vis=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(fun(board,i,j,m,n,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
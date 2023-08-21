//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    
    int isEven(int i, int j, int n, int m, vector<vector<int>> &matrix) {
        int zero = 0;
        
        for(auto d : dir) {
            int x = i + d.first;
            int y = j + d.second;
            
            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 0)
                zero++;
        }
        
        if(zero > 0 && zero%2 == 0)
            return 1;
        
        return 0;
    }
    
    int Count(vector<vector<int> >& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) {
                    ans += isEven(i,j,n,m,matrix);
                }
            }
        }
        
        return ans;
    }
    };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
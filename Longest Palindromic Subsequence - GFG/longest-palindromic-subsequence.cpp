//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
     int lcsHelper(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(n ==-1 || m == -1) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n] == s2[m]){
            dp[n][m] = 1 + lcsHelper(n-1, m-1, s1, s2, dp);
        }
        else dp[n][m] = max(lcsHelper(n-1, m, s1, s2, dp) , lcsHelper(n, m-1, s1, s2, dp));

        return dp[n][m];
        
    }
    
    int longestPalinSubseq(string A) {
        //code here
        
        string str1 = A;
        string str2 = A;
        reverse(str2.begin(), str2.end());
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(n, -1));
        
        return lcsHelper(n-1, n-1, str1, str2,dp );
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
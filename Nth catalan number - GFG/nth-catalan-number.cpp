//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        const int MOD = 1e9 + 7;
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        for (int i =1; i<= n; i++) {
            for (int j=0; j< i; j++) {
                catalan[i] = (catalan[i] + (catalan[j] * 1LL * catalan[i - j - 1]) % MOD) % MOD;
            }
        }
        return catalan[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
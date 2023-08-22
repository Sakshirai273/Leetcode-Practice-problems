//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        unordered_map<int,int> rowmp;
        unordered_map<int,int> colmp;
        
        int mxsum = 0;
        for(int i = 0; i<n; i++)
        {
            int rsum = 0;
            int csum = 0;
            for(int j = 0; j<n; j++)
            {
                rsum += matrix[i][j];
                csum += matrix[j][i];
            }
            mxsum = max(mxsum, max(rsum, csum));
            rowmp[i] = rsum;
            colmp[i] = csum;
        }
        
        int op = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(rowmp[i] == mxsum || colmp[j] == mxsum) continue;
                
                int x = mxsum - max(rowmp[i], colmp[j]);
                rowmp[i] += x;
                colmp[j] += x;
                op += x;
            }
        }
        return op;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
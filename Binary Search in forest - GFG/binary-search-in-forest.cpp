//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        int high = INT_MIN , low = 0;
          for(int i = 0 ; i< n ; i++){
              high = max(high , tree[i]);
          }
          while( low <= high){
              int mid = low + (high-low)/2;
              int wood = f(tree, mid , n);
              
              if(wood == k)
               return mid;
               else if( wood < k)
               high = mid-1;
               else
               low = mid+1;
          }
          return -1;
    }
    int f( int tree[], int mid , int n){
        int wood_sum = 0;
        for(int i = 0 ; i< n ; i++){
            wood_sum += max(0, tree[i] - mid);
        }
        return wood_sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends
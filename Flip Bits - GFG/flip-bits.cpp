//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
       int ans=0,diff=0;
        for(int i=0;i<n;i++)
            if(a[i]==1) ans++;
        int count_zero=0,count_one=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1) count_one++;
            else count_zero++;
            if(count_one>=count_zero)
            {
                count_one=0;
                count_zero=0;
            }
            if(count_zero>count_one) diff=max(diff,count_zero-count_one);
        }
        return diff+ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
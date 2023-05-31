//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
    // code here
        
        map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
     
        int ans = arr[0];
        int minfreq =m[arr[0]];
        
        for(int i=1;i<n;i++){
           int freq = m[arr[i]];
            
            if(freq==minfreq){
                if(arr[i]>=ans){
                    ans = arr[i];
                }
            }
            if(freq<minfreq){
                ans = arr[i];
            }
            
            minfreq = min(freq,minfreq);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
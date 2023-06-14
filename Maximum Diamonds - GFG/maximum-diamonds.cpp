//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        long long int ans=0;
        priority_queue<long long>pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        int count=0;
        while(count<K){
            int temp=pq.top();
            ans+=temp;
            pq.pop();
            pq.push(temp/2);
            count++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
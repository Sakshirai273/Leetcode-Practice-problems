//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
                vector<int>temp;
            int i=0;
            for(int k=0;k<n;k++){
                if(arr[k]>=0){
//possitive element store in temp array;
                    temp.push_back(arr[k]);
                }
                else{
                    // for negative element
                      arr[i]=arr[k];
                      i++;
                }
            }
            for(int k=0;k<temp.size();k++){
                 arr[i++]=temp[k];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends
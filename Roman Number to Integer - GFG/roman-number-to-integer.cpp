//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char,int>mpp;
        mpp['I']=1;
        mpp['V']=5;mpp['X']=10;mpp['L']=50;mpp['C']=100;mpp['D']=500;mpp['M']=1000;
       int n=str.size();
        int sum=mpp[str[n-1]];
        for(int i=n-2;i>=0;i--){
            
            if(mpp[str[i+1]]<=mpp[str[i]])
            sum=sum+mpp[str[i]];
            else{
                sum=sum-mpp[str[i]];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
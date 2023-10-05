//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    long long int fun(string s,int k)
    {
        int i=0,j=0;
        int n=s.size();
        int freq[26]={0};
        int dcount=0;
        long long int ans=0;
        while(j<n)
        {
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1)
            {
                dcount++;
            }
            while(dcount>k)
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0)
                    dcount--;
                i++;
            }
            j++;
            ans+=(j-i+1);
        }
        return ans;
    }
    public:
    long long int substrCount (string s, int k) {
        
        return fun(s,k)-fun(s,k-1);
        //code here.
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
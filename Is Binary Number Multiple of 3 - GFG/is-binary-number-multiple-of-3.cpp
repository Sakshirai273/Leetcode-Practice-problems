//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	   
        int cnt = 0 ;
        
        int n = s.size() ;
        
        int index = 0 ;
        
        for( int i = n-1 ; i >= 0 ; i-- )
        {
            if( s[i] == '1' )
            {
                if(index%2==0) cnt += 1 ;
                else cnt += 2 ;
            }
            index++ ;
        }
        
        return cnt%3 == 0  ;
    }
	};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
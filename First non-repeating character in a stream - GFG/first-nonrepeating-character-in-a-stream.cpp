//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
    string FirstNonRepeating(string A){
    map<char,int> M;    
    queue<char> q;     
    string s;          
    for(int i=0;i<A.size();i++)
    {
        char c = A[i]; 
        M[c]++; 
           
         if(M[c]==1)    
        q.push(c);  
        
        while (!q.empty() && M[q.front()] != 1) {
                    q.pop();
                }
 
        
        if(q.empty()) 
        s.push_back('#');
        
        else
        s.push_back(q.front());
    }
    return s;  
}

	};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
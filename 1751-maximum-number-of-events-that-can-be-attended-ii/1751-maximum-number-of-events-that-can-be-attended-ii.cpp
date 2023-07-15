
class Solution {

public:
    int find(vector<vector<int>>&events,int start,int toFind)
    {
        int low=start;
        int high=events.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(events[mid][0]>toFind)
            {
                ans=mid;
              high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
       // cout<<ans<<endl;
        return ans;
        
    }
    int recur(vector<vector<int>>&dp,int idx,vector<vector<int>>&events,int k)
    {
        if(idx==-1)
            return 0;
        if(idx>=events.size() or k==0)
            return 0;

        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        // Binary Search the value 
        int i=find(events,idx+1,events[idx][1]);
        int op1=recur(dp,idx+1,events,k);
        int op2=events[idx][2]+recur(dp,i,events,k-1);
        
        return dp[idx][k]=max(op1,op2);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {       
        sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             }
            );
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return recur(dp,0,events,k); 
    }
};
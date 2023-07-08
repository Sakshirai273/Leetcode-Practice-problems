class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;
        vector<int>pairSum(m,0);
        
        for(int i = 0 ; i<m; i++){
            pairSum[i] = weights[i]+weights[i+1];
            
        }
        sort(begin(pairSum),end(pairSum));
        long maxSum =0 ;
        long minSum = 0;
        
        for(int i = 0 ; i< k-1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[(m-1)-i];
        }
        return maxSum - minSum;
    }
};

    
    // s.c - o(N)
    // t.c - o(NlogN)
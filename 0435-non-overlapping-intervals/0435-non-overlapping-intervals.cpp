class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        if(n == 1)
            return 0;
        
        sort(intervals.begin(),intervals.end());
        int count =0;
        vector<int> prev= intervals[0];
        for(int i=1 ; i<n ;i++)
        {
            int currSP = intervals[i][0];
            int currEP = intervals[i][1];
            
            int prevSP= prev[0];
          int prevEP= prev[1];
            if(currSP>= prevEP){
                prev = intervals[i];
            }
            else {
                count++;
                if(currEP < prevEP ){
                    prev = intervals[i];
                }
            }
                
        }
        return count;
    }
};














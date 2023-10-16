class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;

        for(int i  = 0 ; i< rowIndex + 1; i++){
            vector<int>curr(i+1 , 1);
            
            for(int j = 1 ; j < i ; j++){
                curr[j] = prev[j] + prev[j -1];
             }
            prev = curr;
        }
        return prev;
    }
};
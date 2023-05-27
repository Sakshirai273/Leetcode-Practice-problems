class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> ans(stoneValue.size() , 0);
        for(int i = ans.size()- 1 ; i>= 0 ; i--){
            int take = 0;
            int best = INT_MIN;
            
            for(int j = 0 ; j< 3 && i+ j < stoneValue.size() ; j++){
                take += stoneValue[i+j];
                int opp = (i+j+1< stoneValue.size()) ? ans[i+j+1]:0;
                best = max( best , take - opp);
                
            }
            ans[i] = best;
        }
      //  return (ans[0]> 0) ? "Alice" : (ans[0] == 0)?:"Bob";
          return (ans[0] > 0) ? "Alice" : (ans[0] == 0) ? "Tie" : "Bob";
    }
};

       

class Solution {
public:
    bool buddyStrings(string s, string goal) {
     if(s.size() != goal.size())
         return false;
        int n = s.size();
        vector<int> freq(26,0);
        vector<int> uneq;
        
        for(int i =0 ; i<n ; i++){
            freq[s[i] -'a']++;
            if(s[i] != goal[i])
                uneq.push_back(i);
        }
        
        if(uneq.size() == 0){
          for(int i : freq)
              if( i >= 2)
                  return true;
        }
        if(uneq.size() != 2)
            return false;
        
        char temp = s[uneq[0]];
        s[uneq[0]] = s[uneq[1]];
        s[uneq[1]] = temp;
        
        return (s==goal);
    }
};
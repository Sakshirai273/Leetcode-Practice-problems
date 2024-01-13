class Solution {
public:
    int minSteps(string s, string t) {
            
        int freq[26] = {0};

        for( int i = 0 ; i < s.length() ; i++)
        {
             freq[s[i]-'a'] += 1;
             freq[t[i]-'a'] -= 1;
        }
        
        
        int ans = 0;

        for( int i = 0 ; i < 26 ; i++)
        {
            ans += abs(freq[i]);   
        }

        return ans / 2;
    }
};
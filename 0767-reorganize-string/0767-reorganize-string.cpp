class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        char c;
        for (auto i : mp) {
            if (i.second > maxi) {
                maxi = i.second;  // majority frequency
                c = i.first;   //  majority character 
            }
        }
        
        if (maxi > (s.size() + 1) / 2) {
            return "";  // Not possible to reorganize.
        }
        string ans(s.size(), ' '); // Create a string of size n
        int idx = 0;
        
        while (mp[c] > 0) {
            ans[idx] = c;  //majority element in ex- if a is majority and freq 4 then a_a_a_a_ like that
            idx += 2;
            mp[c]--; // Decrement the freq.
        }
        
        for (auto i : mp) {
            while (i.second > 0) {
                if (idx >= s.size()) {
                    idx = 1; // now fill old position
                }
                ans[idx] = i.first;  //place it in string ans
                idx += 2;
                i.second--; // Decrement the freq.
            }
        }
        return ans;
    }
};
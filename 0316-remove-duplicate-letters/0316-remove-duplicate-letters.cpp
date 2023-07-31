class Solution {
public:

    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int> freq(26,0);
        vector<bool> seen(26,false);
        
        for(int i=0;i<n;i++) { // freq wale arr me dal do sab
            freq[s[i]-'a']++;
        }

        stack<char> st;
        st.push(s[0]); // stack me phla char krdo push
        seen[s[0]-'a']=true; // seen mark krdo
        freq[s[0]-'a']--; // freq ek kam krdo
        
        for(int i=1;i<n;i++) {
             freq[s[i]-'a']--; // fre kam krdo
            if(seen[s[i]-'a']==true) // agr dkha hua h
            continue;
           
            while(!st.empty() && s[i]<st.top() && freq[st.top()-'a']>0) {
                  char top = st.top();
                st.pop();
                seen[top-'a'] =false;
              //  freq[top-'a']--;
                     
            }
            
              st.push(s[i]);
              seen[s[i]-'a']=true;     
        }
        
        string ans="";
        while(!st.empty()) {
            char top=st.top();
            st.pop();
            ans+=top;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// It should be noted here that if the string is bcab, the best answer is bca, and the last b should be deleted, which seems to contradict the above discussion. Therefore, we need to use a stack to record the characters we saved.
// After each character is deleted, a new s will be generated, and then in this new string s, j=i-1. i.e. i and j are adjacent, the only way to ensure that s[j] deletes without throwing an error. For example, bcabc, when traversing to a, the adjacent c can be deleted. At this time, babc is formed.
// At this time, it is a new string a, and b can be deleted. When the string is bcab, when traversing to a, the previous b is not adjacent to a, so it cannot be deleted.
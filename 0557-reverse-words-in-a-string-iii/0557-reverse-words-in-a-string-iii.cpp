class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        int n = s.size();
        string ans = "";
        for(int i = 0 ; i < n; i++){
            st.push(s[i]);
            if(i == n - 1){
                st.push(' ');
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
                return ans.substr(1,ans.size()-1);
            }
            else if(s[i] == ' '){
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return "";
    }
};
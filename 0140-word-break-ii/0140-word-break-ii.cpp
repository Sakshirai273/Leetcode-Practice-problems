class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(string &str : wordDict){
            st.insert(str);
        }
        vector<string> ans;
        f(0,"",ans,s,st);
        return ans;
    }
    void f(int i , string anstn , vector<string> &ans , string str , unordered_set<string> &st){
        if( i == str.size()){
            ans.push_back(anstn.substr(0 , anstn.size()-1));
            return;
        }
        for(int j = i+1 ; j <= str.size(); j++){
            string temp = str.substr(i , j-i);
            if(st.find(temp) != st.end()){
                f(j ,anstn + temp + " ",ans,str,st);
            }
        }
    }
};
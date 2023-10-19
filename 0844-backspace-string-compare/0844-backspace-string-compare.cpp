class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')st1.push(s[i]);
            else {if(!st1.empty())st1.pop();}
        }
        
        string rem1="";
        
        while(!st1.empty()){
            rem1+=st1.top();
            st1.pop();
        }
        
        for(int i=0;i<t.size();i++){
            if(t[i]!='#')st1.push(t[i]);
            else {if(!st1.empty())st1.pop();}
        }
        
        string rem2="";
        
        while(!st1.empty()){
            rem2+=st1.top();
            st1.pop();
        }
        
        return rem1==rem2;
    }
};
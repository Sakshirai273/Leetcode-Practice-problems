class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        int start = 0;
        int end = 0;
        int n = s.length();

        while(end < n){
            if(s[end] != ' '){
                end++;
            }
            else{
                string temp = s.substr(start, end - start);
                reverse(temp.begin(),temp.end());
                answer = answer + temp + " ";
                
                end++;
                start = end;
            }
        }
        string temp = s.substr(start, end - start); // for last word of string
        reverse(temp.begin(),temp.end());
        
        answer += temp;
        return answer;
    }
};
class Solution {
    private:
    void solve(string digit, string outp, int idx, vector<string> &ans,string map_str[])
    {
        
        //base case
        if(idx>= digit.length())
        {
            ans.push_back(outp);
            return; 
        }
    
    int number= digit[idx] -'0';
    string value = map_str[number];
    
    for(int i =0; i<value.length() ; i++)
    {
        outp.push_back(value[i]);
        solve(digit ,outp ,  idx+1 , ans,map_str);
        outp.pop_back();
    }
    }
        public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length()==0)
            return ans;
         string outp = "";
        int idx=0;
         string map_str[10] = {"" , "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",  "wxyz"};
        
        solve( digits, outp, idx,ans,map_str);
        return ans;
    }
};
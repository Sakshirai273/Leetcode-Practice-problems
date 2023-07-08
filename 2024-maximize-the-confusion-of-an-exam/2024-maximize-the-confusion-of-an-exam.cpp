class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0 ;
        int i=0 , j=0 ;
        unordered_map<char, int> mp;
        
        while(j<n){
            mp[answerKey[j]]++;
        
        while(min(mp['T'],mp['F']) > k){
            mp[answerKey[i]]--;
            i++;
        }
        result = max(result , j-i+1);
        j++;
    }
    return result;
 }
};
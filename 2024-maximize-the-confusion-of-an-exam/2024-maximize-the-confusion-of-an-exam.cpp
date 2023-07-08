class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        //case 1 : 'F' -> 'T'
            int n= answerKey.length();
        int result = 0 ;
        
        int i = 0 , j=0;
        int countf = 0 ;
        
        while(j < n ){
            if(answerKey[j] == 'F'){
                countf++;
            }
            while(countf > k){
                if(answerKey[i] == 'F'){
                    countf--;
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        
        //case 2 : 'T' -> 'F'
             i = 0 , j=0;
        int countt = 0 ;
        
        while(j < n ){
            if(answerKey[j] == 'T'){
                countt++;
            }
            while(countt > k){
                if(answerKey[i] == 'T'){
                    countt--;
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        return result;
        //TWO PASS SLIDING WINDOW 
    }
};
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int colorA = 0;
        int colorB = 0 ;
        for(int i = 0 ; i < n ; i++){
             if( colors [i] == 'A' && colors[i+1] == 'A' && colors[i+2]== 'A') 
                 colorA++;
             if( colors [i] == 'B' && colors[i+1] == 'B' && colors[i+2]== 'B') 
                 colorB++;
            
        }
         if( colorA > colorB)
                 return true;
            else
                return false;
    }
};
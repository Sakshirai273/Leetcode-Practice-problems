class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bit1;
        int bit2;
        int bit3;
        unordered_map<string , int> mp;
        int ans = 0;
        while( a|| c|| b){
            bit1 = (a&1);
            bit2 = (b&1);
            bit3 = (c&1);
            
            if((bit1 | bit2) != bit3){
                if(bit1 & bit2)
                    ans += 2;
                else 
                    ans ++;
                
            }
            c = c>>1;
            b = b>>1;
            a = a>>1;
        }
        return ans;
        
    }
};

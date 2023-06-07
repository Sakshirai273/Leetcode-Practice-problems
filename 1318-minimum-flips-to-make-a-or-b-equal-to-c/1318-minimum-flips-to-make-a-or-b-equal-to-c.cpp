class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bit1;
        int bit2;
        int bit3;
        unordered_map<string , int> mp;
        mp.insert({"0#0#1" , 1});
        mp.insert({"1#0#0" , 1});
         mp.insert({"0#1#0" , 1});
         mp.insert({"1#1#0" , 2});
        int ans = 0;
        while( a> 0 || c>0 || b>0){
            bit1 = (a&1);
            bit2 = (b&1);
            bit3 = (c&1);
            
            if((bit1 | bit2) != bit3){
                string str = to_string(bit1) + "#" + to_string(bit2) + "#" + to_string(bit3);
                ans += mp[str];
            }
            c = c>>1;
            b = b>>1;
            a=  a>>1;
        }
        return ans;
        
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int result = nums.size(); 
        for(int i = 0  ; i< nums.size() ; i++){ 
            result ^= nums[i];
            result ^= i; 
        }
        return result; 
    }
};
// array ke har number ka (0-n) jitne number aate hain unse XOR krenge 
// Ex. [0,1,3,4]
// 0 - N -> [0^1^2^3^4]^[0^1^3^4]
// ans -> 2 ( Kyuki baaki sab zero hojayenge)        
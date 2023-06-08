class Solution {
public:
    int minFlips(int a, int b, int c) {
//         int result = (( a|b) ^ c); // no of flips 
        
//         //if both bits are 1 in a and b - a&b
//         int result1 = (a&b);
//         int result2 = (result1 & result); 
        
//      //   return __builtin_popcount(result) + __builtin_popcount(result2);  // built in function to count no . of bitsets (no. of 1 bits)
        return __builtin_popcount (((a|b) ^ c)) + __builtin_popcount((a&b) & (( a|b) ^ c)); 
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         unsigned int rev = 0;
          for (int i = 0; i < 32; i++) {
               rev = rev << 1; // left shift by 1
               if( n & 1 )
                   rev = rev ^ 1;
              // or we can do: - rev = rev + (n&1);
                    n = n >> 1;
          }
        return rev;
    }
};


// APPROACH TAKEN FROM GFG

































































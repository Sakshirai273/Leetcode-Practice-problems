class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long mask = (1L<<31) , ans =0;
        for( int i = 31; i >= 0 ; i--){
            int cnt  = 0 ;
            for( int j = 0 ; j<nums.size() ;j++){
                if(nums[j] & mask)
                    cnt++;
            }
            if( cnt %3 != 0)
                ans+= mask;
                mask >>= 1;
            }
            return ans;
    }
};
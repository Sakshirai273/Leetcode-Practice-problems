class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int zerocnt = 0;
        int maxi =0;
        int i =0;
         for(int j = 0 ; j< nums.size() ;j++){
             if(nums[j] == 0)
                 zerocnt++;
             
             while (zerocnt>1){
                 if(nums[i]==0)
                      zerocnt--;
                      i++;
                 }
               maxi = max(maxi , j-i);  
             }
             return maxi;
         }
};
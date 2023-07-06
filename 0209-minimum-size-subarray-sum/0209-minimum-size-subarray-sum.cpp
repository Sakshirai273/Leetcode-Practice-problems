class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int minlen=INT_MAX; //max assign krte hain jab min nikaalna ho
        int sum=0;
        while(right < nums.size())
        {
            sum += nums[right];
            right++;
            while(sum >= target) //chota krna chah rhe hain window ko
            {
                minlen = min(minlen , right - left);   //left ko shift krenge taki minimum size window mile
                sum -= nums[left]; //sum  ko bhi chota krte rhenge sath sath
                left++;        //right shift of left
            }
        }
        return(minlen==INT_MAX)?0:minlen;  
    }
};



//jaha bhi subarray ya "contiguous" subarray jesa word use kiya gaya ho vaha sliding window ka concept consider krlena hai ek baar
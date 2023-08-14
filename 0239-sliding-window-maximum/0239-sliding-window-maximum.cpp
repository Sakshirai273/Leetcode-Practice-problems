class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(!dq.empty() && dq.front() == i-k) // out of bound will be removed 
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i]) // whatever is at the back and remove all the elements that are smaller than  or equal to a[i]
                dq.pop_back(); //
            
            dq.push_back(i);
            if( i >= k-1) // start taking subarray maximums
                ans.push_back(nums[dq.front()]);
        }    
    return ans;
    }
};
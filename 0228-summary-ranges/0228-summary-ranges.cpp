class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		
        vector<string> result;
        
        int n = nums.size();
        if(n == 0 )
        return result;
        
        int start = nums[0];
        
        for(int i = 0; i<n; i++)
        {
			
            if( i == n-1 || nums[i]+1 != nums[i+1])
            {
			    // if current element is not equals start , this means we have found a range.
                if(nums[i] != start)
                    result.push_back(to_string(start)+ "->"+ to_string(nums[i]));
					

                else
                        result.push_back(to_string(start));
                
                if(i != n-1)
                    start = nums[i+1];
            }
        }
		
        return result;
    }
};
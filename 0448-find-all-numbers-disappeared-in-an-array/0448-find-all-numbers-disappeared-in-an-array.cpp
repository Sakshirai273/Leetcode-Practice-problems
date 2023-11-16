class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+1, 0); // frequency vector
		vector<int>res{}; // result vec
        
		// Compute frequency
        for(auto num: nums){
            freq[num]++;
        }
        
		// Compute missing elements
        for(int i{1}; i<=n; ++i){
            if(!freq[i])
                res.push_back(i);
        }
        
        return res;
    }
};
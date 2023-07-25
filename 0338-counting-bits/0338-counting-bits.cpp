class Solution {
public:
    vector<int> countBits(int n) {
       // int m = countBits.size();
        vector<int> vec;        
        for(int i = 0 ; i<= n ; i++){
            // sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num)
            {
				  if(num&1){
                sum++;
              }
                num >>= 1;
            }
            vec.push_back(sum);
        }
    return vec;
    }
};
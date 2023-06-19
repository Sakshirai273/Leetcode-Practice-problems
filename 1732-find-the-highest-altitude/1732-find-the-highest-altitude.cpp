class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int count = 0;
        
        for (int s : gain) {
            count += s;
            result = max(result, count);
        }
        
        return result;
    }
};   

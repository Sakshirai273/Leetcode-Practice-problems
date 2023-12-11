class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int y = n / 4;
        map<int, int> mp;
        
        for(auto it : arr)
        {
            mp[it]++;
        }

         for(int i = 0 ; i < n ; i++){
             if(mp[arr[i]]>y)
                {
                  return arr[i];
            }
        }
       return -1;
    }
};
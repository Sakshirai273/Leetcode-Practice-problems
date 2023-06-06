class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
    set<int>st;
        int mini = arr[0];
        int maxi = arr[0];
        
        for(int i = 0 ; i< n ; i++){
            st.insert(arr[i]);
            maxi = max(maxi , arr[i]);
            mini = min(mini, arr[i]);
            
        }
        int num = mini;
        int d =(maxi - mini) /(n-1);
        if(d == 0 && st.size()>1)
            return false;
        int cnt = n;
        while(cnt > 0){
            if(st.find(num) == st.end())
                return false;
            
            num =  num + d;
            cnt --;
        }
        return true;
    }
};
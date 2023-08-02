class Solution {
public:
        void solve(int s,int &n,vector<vector<int>> &ans,vector<int> &arr){
        if(s>=n){
        ans.push_back(arr);
            return;
        }
        for(int i = s; i < n; i++){
            swap(arr[i],arr[s]);
            solve(s+1,n,ans,arr);
            swap(arr[i],arr[s]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0,n,ans,nums);
        return ans;
    }
};
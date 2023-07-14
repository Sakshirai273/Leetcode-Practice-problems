class Solution {
public:
int longestSubsequence(vector<int>& arr, int diff) {
 unordered_map<int,int> mp;
 int maxi=0;
for(auto i: arr){
    if(mp.count(i-diff))
       mp[i]=mp[i-diff]+1;
    else
    mp[i]=1;
       maxi=max(maxi,mp[i]);
    }
       return maxi;
    }
  };

// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int diff) {
//         int res = 1;
//         unordered_map<int,int> mp; // key : element in arr ; value : longest length for AS based on diff
//         for(int i = 0 ; i < arr.size() ; i++){
//             mp[arr[i]] = mp[arr[i]-diff]+1;
//             res = max(res,mp[arr[i]]);
//         }
//         return res;
//     }
// };

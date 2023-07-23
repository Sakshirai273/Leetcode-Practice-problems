/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};
        dp.resize(n+1,{});
        return f(n);
    }
    vector<TreeNode*> f(int n){
        if(n==1)return {new TreeNode(0)};
        if(dp[n].size()!=0)return dp[n];
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> l=f(i);
            vector<TreeNode*> r=f(n-1-i);
            for(auto &it:l){
                for(auto &it2:r){
                    TreeNode* temp=new TreeNode(0);
                    temp->left=it;
                    temp->right=it2;
                    ans.push_back(temp);
                }
            }
        }
        return dp[n]=ans;
    }
};
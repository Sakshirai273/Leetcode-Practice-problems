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
    unordered_map<int, int> mp;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int>ans;
        int maxi = INT_MIN;
        
        for(auto i : mp){
            maxi = max(maxi, i.second);
        }
        for(auto j : mp){
            if(j.second == maxi){
                ans.push_back(j.first);
            }
        }
        return ans;
    }
};
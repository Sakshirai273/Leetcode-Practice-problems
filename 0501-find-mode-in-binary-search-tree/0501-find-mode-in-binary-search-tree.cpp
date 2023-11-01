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
    int cnt=0;
    int maxi=0;
    int curr=0;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        
        f(root);
        cnt=0;
        curr=0;
        // cout<<maxi;
        f2(root);
        return ans;
    }
    
    void f(TreeNode* root){
        if(root==NULL)return;
        f(root->left);
        // if(maxi==0)curr=root->val;
        if(root->val==curr)cnt++;
        else {
            cnt=1;
            curr=root->val;
        }
        // cout<<cnt;
        maxi=max(maxi,cnt);
        f(root->right);
    }
    
    void f2(TreeNode* root){
        if(root==NULL)return;
        f2(root->left);
        if(root->val==curr)cnt++;
        else {
            cnt=1;
            curr=root->val;
        }
        // cout<<cnt;
        if(cnt==maxi)ans.push_back(curr);
        f2(root->right);
    }
    
};
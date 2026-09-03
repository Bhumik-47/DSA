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
    int rob(TreeNode* root) {
        vector<int>ans(2,0);
        ans=getMaxSum(root);
        return max(ans[0],ans[1]);
    }
    vector<int> getMaxSum(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        vector<int>ln(2,0);
        ln=getMaxSum(root->left);
        vector<int>rn(2,0);
        rn=getMaxSum(root->right);

        vector<int>op(2,0);
        op[0]=root->val+ln[1]+rn[1];

        op[1]=max(ln[0],ln[1])+max(rn[0],rn[1]);

        return op;
    }
};
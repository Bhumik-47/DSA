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
    int a = 0;
    pair<int,int> fun(TreeNode*r){
        if(r==NULL){
            return {0,0};
        }
        pair<int,int>v1=fun(r->left);
        pair<int,int>v2=fun(r->right);
        int s = v1.first + v2.first + r->val;
        int nc= v1.second + v2.second +1;
        if(r->val==s/nc)a++;

        return {s,nc};
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return a;
    }
};
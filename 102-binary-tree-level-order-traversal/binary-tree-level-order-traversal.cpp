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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>a;
        if(!root)return a;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            vector<int>l;
            for(int i=0;i<x;i++){
                TreeNode*n=q.front();
                l.push_back(n->val);
                q.pop();
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);

            }
            a.push_back(l);
        }
        return a;
    }
};
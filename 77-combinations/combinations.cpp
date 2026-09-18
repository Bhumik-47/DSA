class Solution {
public:
    void com(int n, int k , vector<int>&v,int i, vector<vector<int>>&ans){
         if(v.size()==k){
        ans.push_back(v);
        return;
        }
        if ((int)v.size() + (n - i + 1) < k){
        return;
       }
       
        v.push_back(i);
        com(n,k,v,i+1,ans);
        v.pop_back();
        com(n,k,v,i+1,ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        int i=1;
        vector<vector<int>>ans;
        com(n,k,v,i,ans);
        return ans;
    }
};
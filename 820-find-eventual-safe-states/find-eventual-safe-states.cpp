class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&a,vector<vector<int>>& graph){
        vis[node]=2;
        for(auto it:graph[node]){
            if(vis[it]==0){if(dfs(it,vis,a,graph))return true;}
            else if(vis[it]==2)return true;
        }
        a.push_back(node);
        vis[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>a;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,a,graph);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};
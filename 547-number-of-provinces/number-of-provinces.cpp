class Solution {
public:
    void dfs(int i,vector<bool>&vis, vector<vector<int>>&adj){
        vis[i]=1;
        for(int j:adj[i]){
            if(vis[j]==0)
            dfs(j,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        int a=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                a++;
                dfs(i,vis,adj);
            }
        }
        
        return a;
    }
};
class Solution {
public:
    int dfs(int node,vector<vector<int>>&children,vector<int>& op, vector<int>& score){
        if(children[node].size()==0){
            return score[node];
        }
        int sdp=0,mindp=1e9;
        for(int u:children[node]){
            int sc=dfs(u,children,op,score);
            sdp+=sc;
            mindp=min(mindp,sc);
        }
        if(op[node]==0){
            return score[node]+sdp-min(0,mindp);
        }
        else{
            return score[node]+sdp-mindp;
        }
        return 0;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>children(n);
        for(int i=1;i<n;i++){
            children[parent[i]].push_back(i);
        }
        return dfs(0,children,op,score);
    }
};
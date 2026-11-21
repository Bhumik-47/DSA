class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.front();
            int dis=it.first;
            int node=it.second.first;
            int stop=it.second.second;
            pq.pop();
            for(auto itt:adj[node]){
                int edgwg=itt.second;
                int no=itt.first;
                if(dis+edgwg<dist[no] && stop<=k ){
                    dist[no]=dis+edgwg;
                    pq.push({dist[no],{no,stop+1}});
                }
            }
        }
     return dist[dst]==1e9?-1:dist[dst];
    }
};
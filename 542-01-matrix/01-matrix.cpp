class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){dist[i][j]=0;
                q.push({i,j});}
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]==1){
                    if(1+dist[r][c]<dist[nx][ny]){dist[nx][ny]=1+dist[r][c];
                    q.push({nx,ny});
                }
                }
            }
        }
        return dist;
    }
};
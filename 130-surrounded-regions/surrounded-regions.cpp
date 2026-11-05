class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>&board,vector<vector<int>>&vis){
        int m=board.size();
        int n=board[0].size();
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;  //0 X 0
                                 //X 0 X
                                 //0 X 0
        q.pop();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nx=r+dx[k];
            int ny=c+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && board[nx][ny]=='O'){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O')bfs(i,0,board,vis);
            if(!vis[i][n-1] && board[i][n-1]=='O')bfs(i,n-1,board,vis);
        }
        for(int i=0;i<n;i++){
            if(!vis[0][i] && board[0][i]=='O')bfs(0,i,board,vis);
            if(!vis[m-1][i] && board[m-1][i]=='O')bfs(m-1,i,board,vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};
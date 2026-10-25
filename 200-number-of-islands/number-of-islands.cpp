class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        grid[r][c]='2';
        int rr[4]={-1,0,1,0};
        int cc[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
                int nr=r+rr[i];
                int nc=c+cc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                    dfs(nr,nc,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int a=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    a++;
                    dfs(i,j,grid);
                }
            }
        }
        return a;
    }
};
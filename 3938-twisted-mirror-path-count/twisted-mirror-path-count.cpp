class Solution {
public:
    long long fun(int i, int j,int d, vector<vector<int>>& grid,vector<vector<vector<long long>>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;
        if(dp[i][j][d]!=-1)return dp[i][j][d];
        if(grid[i][j]==1){
            if(d)return dp[i][j][d]=fun(i+1,j,0,grid,dp);
            return dp[i][j][d]=fun(i,j+1,1,grid,dp);
        }
        return dp[i][j][d]=(fun(i+1,j,0,grid,dp)+fun(i,j+1,1,grid,dp))%(1000000007LL);
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return fun(0,0,0,grid,dp);
    }
};
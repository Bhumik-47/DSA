class Solution {
public:
     long long getMinSum(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&memo){
        int m=grid.size();
        int n=grid[0].size();
        if(memo[i][j]!=-1)return memo[i][j];
        if(i==0 && j==0)return grid[0][0];
        else if(i==0){memo[i][j]=grid[i][j]+getMinSum(grid,0,j-1,memo);
        return memo[i][j];
        }
        else if(j==0){memo[i][j]= grid[i][j]+getMinSum(grid,i-1,0,memo);
        return memo[i][j];
        }
        else{
            
            memo[i][j]=grid[i][j]+min(getMinSum(grid,i-1,j,memo),getMinSum(grid,i,j-1,memo));
            return memo[i][j];
        }
    }
    int minPathSum(vector<vector<int>>& grid) { 
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return getMinSum(grid,m-1,n-1,memo);
        
    }
};
class Solution {
public:
    int fun(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(i==coins.size())return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
          int skip=1e9;
        skip=fun(coins,amount,i+1,dp);
        int take = 1e9;
        if(coins[i]<=amount){
            take=1+fun(coins,amount-coins[i],i,dp);
        }
      
        return dp[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= fun(coins,amount,0,dp);
        return ans>=1e9?-1:ans;
    }
};
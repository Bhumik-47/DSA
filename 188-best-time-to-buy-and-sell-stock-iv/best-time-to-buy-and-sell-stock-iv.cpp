class Solution {
public:
    int solve(vector<int>&prices, vector<vector<int>>&dp, int i, int trans, int k){
        if(i>=prices.size() || trans==2*k)return 0;
        if(dp[i][trans]!=-1)return dp[i][trans];
        if(trans%2==0){
            return dp[i][trans]=max(-prices[i]+solve(prices,dp,i+1,trans+1,k),solve(prices,dp,i+1,trans,k));
        }
        else{
            return dp[i][trans]=max(prices[i]+solve(prices,dp,i+1,trans+1,k),solve(prices,dp,i+1,trans,k));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(k*2,-1));
        return solve(prices,dp,0,0,k);
    }
};
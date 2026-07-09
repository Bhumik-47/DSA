class Solution {
public:
    int solve(vector<int>&prices, vector<vector<int>>&dp, int i, int trans){
        if(i>=prices.size() || trans==4)return 0;
        if(dp[i][trans]!=-1)return dp[i][trans];
        if(trans%2==0){
            return dp[i][trans]=max(-prices[i]+solve(prices,dp,i+1,trans+1),solve(prices,dp,i+1,trans));
        }
        else{
            return dp[i][trans]=max(prices[i]+solve(prices,dp,i+1,trans+1),solve(prices,dp,i+1,trans));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(prices,dp,0,0);
    }
};
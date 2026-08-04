class Solution {
public:
    int fun(vector<int>& cost,vector<int>&dp ){
        dp[0]=0;
        dp[1]=0;
        int n=cost.size();
        for(int i=2;i<n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
                }
        return min(dp[n-1]+cost[n-1],dp[n-2]+cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,0);
        return fun(cost,dp);
    }
};
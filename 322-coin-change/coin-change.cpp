class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (amount == 0) return 0;
        
        // Use a safe upper bound for "infinity"
        // INT_MAX - 1 allows us to safely do (1 + dp[...]) without overflow
        int INF = INT_MAX - 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) {
                    dp[i][j] = 0; // 0 coins needed to make amount 0
                } 
                else if (i == 0) {
                    dp[i][j] = INF; // Impossible to make amount > 0 with 0 coins
                } 
                else if (coins[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                } 
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // If the value is still our placeholder, it's impossible to form the amount
        return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
    }
};
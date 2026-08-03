class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i % 4] will store the optimal score difference at index i
        vector<int> dp(4, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            int maxScore = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                // Access dp[i + k + 1] using modulo 4
                maxScore = max(maxScore, take - dp[(i + k + 1) % 4]);
            }

            dp[i % 4] = maxScore;
        }

        int result = dp[0];
        if (result > 0) return "Alice";
        if (result < 0) return "Bob";
        return "Tie";
    }
};
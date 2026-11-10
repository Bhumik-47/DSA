class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // These represent dp[idx + 1], dp[idx + 2], and dp[idx + 3]
        // Initially, we are at idx = n - 1, so dp1 represents dp[n] (the top), which is 0.
        int dp1 = 0; 
        int dp2 = 0; 
        int dp3 = 0; 
        
        for (int idx = n - 1; idx >= 0; idx--) {
            int i = idx - 1; 
            
            // take1 only relies on the immediately next step (dp1)
            int take1 = 1 + costs[i + 1] + dp1;
            int take2 = INT_MAX, take3 = INT_MAX;
            
            // take2 relies on two steps ahead (dp2)
            if (i < n - 2)
                take2 = 4 + costs[i + 2] + dp2;
            
            // take3 relies on three steps ahead (dp3)
            if (i < n - 3)
                take3 = 9 + costs[i + 3] + dp3;
                
            int current_dp = min({take1, take2, take3});
            
            // Shift the variables for the next iteration (moving leftwards)
            dp3 = dp2;
            dp2 = dp1;
            dp1 = current_dp;
        }
        
        // After the loop finishes, idx reaches 0. 
        // current_dp is stored in dp1, which corresponds to the starting point (i = -1).
        return dp1;
    }
};
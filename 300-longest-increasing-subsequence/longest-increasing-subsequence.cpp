class Solution {
public:
    int rec(vector<int>& nums, int i, int prev_idx, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        
        // Coordinate shift: prev_idx of -1 is mapped to row 0 in the DP table
        if (dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];
        
        // Option 1: Always allowed to skip the current element
        int skip = rec(nums, i + 1, prev_idx, dp);
        
        // Option 2: Take the current element (only if it's the first element or strictly greater)
        int take = 0;
        if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
            take = 1 + rec(nums, i + 1, i, dp);
        }
        
        // Cache and return the result
        return dp[i][prev_idx + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp table of size [n][n + 1] initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(nums, 0, -1, dp);
    }
};
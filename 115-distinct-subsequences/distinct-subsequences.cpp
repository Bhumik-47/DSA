class Solution {
public:
    // Changed return type to long long to handle intermediate overflows
    long long solve(int idx1, int idx2, string &s, string &t, vector<vector<long long>>& dp){
        if(idx2 < 0) return 1;
        if(idx1 < 0) return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2]) {
             dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, s, t, dp) + solve(idx1 - 1, idx2, s, t, dp);
        }
        else
         dp[idx1][idx2] = solve(idx1 - 1, idx2, s, t, dp);
         return dp[idx1][idx2];
         
    }
    
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        // DP table uses long long
        vector<vector<long long>> dp(n1, vector<long long>(n2, -1));
        
        // Cast the final result back to int
        return (int)solve(n1 - 1, n2 - 1, s, t, dp);
    }
};
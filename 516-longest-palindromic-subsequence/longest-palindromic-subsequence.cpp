class Solution {
public:
    int dpp(string&s,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+dpp(s,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=max(dpp(s,i+1,j,dp),dpp(s,i,j-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if(n==1)return 1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return dpp(s,0,n-1,dp);
    }
};
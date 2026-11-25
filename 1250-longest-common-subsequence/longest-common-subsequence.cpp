class Solution {
public:
int longcommsub(string&s1, string&s2, int i, int j,vector<vector<int>>&dp){
       
          if(i==s1.size() || j==s2.size())
              return 0;
          if(dp[i][j]!=-1)return dp[i][j];
          if(s1[i]==s2[j])
              return dp[i][j]=1 + longcommsub(s1, s2, i+1, j+1,dp);
         else{
             return dp[i][j]=max(longcommsub(s1, s2, i + 1, j,dp), longcommsub(s1, s2, i, j + 1,dp));
         }
        
}
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(); int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return  longcommsub(s1, s2, 0, 0,dp);
    }
};
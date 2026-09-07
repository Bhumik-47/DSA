class Solution {
public:
    
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long>v(26,0);
        long long dp=1;
        long long m = 1000000007;
        for(int i=0;i<n;i++){
            int id = s[i]-'a';
            long long olddp = dp;
            dp = (2*dp-v[id]+m)%m;
            v[id] = olddp;

        }
        return (dp-1+m)%m;

    }
};
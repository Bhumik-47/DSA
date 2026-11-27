class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(); int l=0; int an=0;  //abcda
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
        if(mp.find(s[i])!=mp.end()){
            l=max(mp[s[i]]+1,l);
        }
        mp[s[i]]=i;
        an=max(an,i-l+1);
        }
        return an;
    }
};
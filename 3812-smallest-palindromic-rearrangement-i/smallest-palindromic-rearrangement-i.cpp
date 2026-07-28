class Solution {
public:
    string smallestPalindrome(string s) {
    int n=s.size();
    int len=n/2;
    vector<int>v(26,0);
    for(int i=0;i<len;i++)
    v[s[i]-'a']++;
    
    int l=0,r=n-1;
    for(int i=0;i<26;i++){
        while(v[i]){
            s[l++]=i+'a';
            s[r--]=i+'a';
            v[i]--;
        }
    }
    return s;
    }
};
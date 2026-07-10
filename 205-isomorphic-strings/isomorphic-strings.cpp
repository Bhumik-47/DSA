class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>v;
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++){
           if(v.find(s[i])==v.end()){
            v[s[i]]=t[i];
           }
           else if(v[s[i]]!=t[i])return false;
        }
        unordered_map<char,char>b;
        for(int i=0;i<n1;i++){
           if(b.find(t[i])==b.end()){
            b[t[i]]=s[i];
           }
           else if(b[t[i]]!=s[i])return false;
        }
        return true;
    }
};
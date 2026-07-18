class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int>v(26,0);
        for(char c:s)v[c-'a']++;
        string t="";
        while(v[y-'a']!=0){
            t+=y;
            v[y-'a']--;
        }
        for(int i=0;i<s.size();i++){
           if(v[s[i]-'a'])t+=s[i];
        }
        return t;
    }
};
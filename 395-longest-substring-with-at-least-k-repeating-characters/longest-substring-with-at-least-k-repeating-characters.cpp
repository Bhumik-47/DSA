class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int ml=0;
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
               v[s[j]-'a']++;
               bool b=0;
               for(int i=0;i<26;i++){
                if(v[i]>0 && v[i]<k){b=1; break;}
               
            }
            if(!b)ml=max(ml,j-i+1);
        }
        }
        return ml;
    }
};
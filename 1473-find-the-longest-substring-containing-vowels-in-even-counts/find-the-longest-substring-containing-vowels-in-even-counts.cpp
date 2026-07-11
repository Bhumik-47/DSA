class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int xorr = 0;
        int maxil=0;
        vector<int>mp(32,-2);
        mp[0]=-1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            switch (ch){
                case 'a':
                  xorr^=1;
                  break;
                case 'e':
                  xorr^=2;
                  break;
                case 'i':
                  xorr^=4;
                  break;
                case 'o':
                  xorr^=8;
                  break;
                case 'u':
                  xorr^=16;
                  break;
            }
            int prev = mp[xorr];
            if(prev==-2){
                mp[xorr]=i;
            }
            else{
                maxil=max(maxil,i-prev);
            }
        }
        return maxil;
    }
};
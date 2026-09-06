class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        s=s+s;
        int i=0,a=0;
        while(i<n){
        int sc=0;
        for(int j=i;j<(i+n)-1;j++){
            if(s[j]==s[j+1])sc++;
        }
        if(sc==k)a++;
        i++;
        }
        return a;
    }
};
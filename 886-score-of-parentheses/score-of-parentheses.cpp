class Solution {
public:
    int scoreOfParentheses(string s) {
        int a=0,c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
            }else{
                c--;
                if(s[i-1]=='('){
                    a+=1<<c;
                }
            }
        }
        return a;
    }
};
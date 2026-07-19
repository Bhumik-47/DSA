class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>l(26);
        for(int i=0;i<s.size();++i)l[s[i]-'a']=i;
        vector<bool>inst(26,false);
        string ret;
        for(int i=0;i<s.size();++i){
            char ch=s[i];
            if(inst[ch-'a'])continue;
            while(!ret.empty() && ret.back()>ch && l[ret.back()-'a']>i){
                inst[ret.back()-'a']=false;
                ret.pop_back();
            }
            ret.push_back(ch);
            inst[ch-'a']=true;
        }
        return ret;
    }
};
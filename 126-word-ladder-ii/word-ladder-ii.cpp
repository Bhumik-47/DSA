class Solution {
private:
    void dfs(string cur,vector<string>&vec,vector<vector<string>>&ans,string&b,unordered_map<string,int>&mp){
        if(cur==b){
        reverse(vec.begin(),vec.end());
        ans.push_back(vec);
        reverse(vec.begin(),vec.end());
        return;
        }
        int step=mp[cur];
        for(int i=0;i<cur.size();i++){
            char ch=cur[i];
            for(char chh='a';chh<='z';chh++){
                cur[i]=chh;
                if(mp.find(cur)!=mp.end() && mp[cur]+1==step){
                    vec.push_back(cur);
                    dfs(cur,vec,ans,b,mp);
                    vec.pop_back();
                }
            }
            cur[i]=ch;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        vector<vector<string>>ans;
        unordered_map<string,int>mp;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push(beginWord);
        mp[beginWord]=1;
        st.erase(beginWord);
        while(!q.empty()){
            string f=q.front();
            int level=mp[f];
            q.pop();
            if(f==endWord)break;
            for(int i=0;i<f.size();i++){
                char ch=f[i];
                for(char chh='a';chh<='z';chh++){
                    f[i]=chh;
                    if(st.find(f)!=st.end()){
                        mp[f]=level+1;
                        st.erase(f);
                        q.push(f);
                    }
                }
                f[i]=ch;
            }
        }
       
        if(mp.find(endWord)!=mp.end()){
        vector<string>vec;
        vec.push_back(endWord);
        dfs(endWord,vec,ans,beginWord,mp);
        }
        return ans;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string s=q.front().first;
            int stt=q.front().second;
            q.pop();
            if(s==endWord)return stt;
            for(int i=0;i<s.size();i++){
                char o= s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,stt+1});
                        st.erase(s);
                    }
                }
                s[i]=o;
            }
        }
        return 0;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int>st;
        vector<int>v(n);
        int i=n-1;
        while(i>=0){
           
            while(!st.empty()&&t[st.top()]<=t[i]){
                st.pop();
            }
            if(!st.empty())v[i]=st.top()-i;
            st.push(i);
            i--;
        }
        return v;
    }
};
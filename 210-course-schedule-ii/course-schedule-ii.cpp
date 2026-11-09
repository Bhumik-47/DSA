class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<vector<int>>v(numCourses);
        vector<int>id(numCourses,0);
        vector<int>r;
        for(auto it:prerequisites){
            v[it[1]].push_back(it[0]);
            id[it[0]]++;
        }
        int nc=0;
        queue<int>q;
        for(int it=0;it<numCourses;it++){
            if(id[it]==0)q.push(it);
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            r.push_back(n);
            nc++;
            for(int it:v[n]){id[it]--;
            if(id[it]==0)q.push(it);
            }
        }
        if(r.size()<numCourses)return {};
        return r;
    
    }
};
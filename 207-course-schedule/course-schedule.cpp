class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        vector<int>id(numCourses,0);
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
            nc++;
            for(int it:v[n]){id[it]--;
            if(id[it]==0)q.push(it);
            }
        }
        return nc==numCourses;
    }
};
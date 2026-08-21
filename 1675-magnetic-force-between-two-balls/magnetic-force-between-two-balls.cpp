class Solution {
public:
    bool can(int x, vector<int>&position, int m){
        int n = position.size();
        int lp=position[0];
        int np=1;
        for(int i=1;i<n && np<m;i++){
           if(position[i]-lp>=x){
            lp=position[i];
            np++;
           }
        }
        return np==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int ans = 0;
        int low = 1;
        int high = (position[n-1]-position[0])/(m-1);
        while(low<=high){
            int x = low+(high-low)/2;
            if(can(x,position,m)){
                ans=x;
                low=x+1;
            }
            else
                high=x-1;
        }
        return ans;
    }
};
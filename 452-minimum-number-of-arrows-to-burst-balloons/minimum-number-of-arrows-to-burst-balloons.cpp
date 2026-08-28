class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)return 1;
        sort(points.begin(),points.end());
        int na=0,i=0,cr=0;
        while(i<n-1){
           cr=points[i][1];
           while(i<n-1 && cr>=points[i+1][0]){
            cr=min(cr,points[i+1][1]);
            i++;
           };
           
           na++;
           i++;
        }
        if(cr<points[n-1][0])na++;
        return na;
    }
};
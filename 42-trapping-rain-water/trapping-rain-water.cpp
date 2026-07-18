class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int s=0,e=n-1;
        int trap=0;
        int maxlef=0,maxright=0;
        while(s<e){
         maxlef=max(maxlef,height[s]);
         maxright=max(maxright,height[e]);
         if(maxlef<maxright){
            trap+=maxlef-height[s];
            s++;
         }
         else{
            trap+=maxright-height[e];
            e--;
         }
         
        }
        return trap;
    }
};
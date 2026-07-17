class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        int ans=0;
        int n=0;
        for(int i=0;i<boxTypes.size();i++){
            if(n+boxTypes[i][0]<=truckSize){
                ans+=boxTypes[i][1]*boxTypes[i][0];
                n+=boxTypes[i][0];
            }
            else if(n+boxTypes[i][0]>truckSize){
                 ans+=boxTypes[i][1]*(truckSize-n);
                 break;
            }
        }
        return ans;
    }
};
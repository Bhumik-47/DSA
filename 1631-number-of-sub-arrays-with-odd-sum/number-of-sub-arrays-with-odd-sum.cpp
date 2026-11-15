class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int m=1e9+7;
        int ev=1,od=0;
        int a=0,s=0;
        for(int i=0;i<n;i++){
          s+=arr[i]%m;
          if(s%2==0){
            a=(a+od)%m;
            ev++;
          }
          else{
            a=(a+ev)%m;
            od++;
          }
        }
        return a;
    }
};
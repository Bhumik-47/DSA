class Solution {
public:
    long long solve(vector<int>& arr, int k, int i,vector<int>&memo){
        if(i>=arr.size())return 0;
        if(memo[i]!=-1)return memo[i];
        int maxi=INT_MIN;
        int j;
        long long gsum=0;
        for(j=i;j<i+k&&j<arr.size();j++){
        maxi=max(arr[j],maxi);
       
        long long sum=1LL*(j-i+1)*maxi+solve(arr,k,j+1,memo);
        gsum=max(gsum,sum);
        }
       return memo[i]=gsum;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>memo(arr.size(),-1);
        return solve(arr,k,0,memo);
    }
};
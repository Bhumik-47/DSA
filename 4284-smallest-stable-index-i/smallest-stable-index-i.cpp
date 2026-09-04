class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prmx(n,0);
        vector<int>sfmn(n,0);
        prmx[0]=nums[0];
        for(int i=1;i<n;i++){
            prmx[i]=max(nums[i],prmx[i-1]);
        }
        sfmn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sfmn[i]=min(nums[i],sfmn[i+1]);
        }
        for(int i=0;i<n;i++){
            if(prmx[i]-sfmn[i]<=k)return i;
        }
        return -1;
    }
};
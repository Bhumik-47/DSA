class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int>ans(n-k+1),counter(50);
    for(int i=0; i<n; i++){
        if(nums[i]<0)counter[nums[i]+50]++;
        if(i-k>=0 && nums[i-k]<0)counter[nums[i-k]+50]--;
        if(i-k+1<0)continue;
        for(int j=0,c=0;j<50;j++){
        c+=counter[j];
        if(c>=x){
            ans[i-k+1]=j-50;
            break;
        }
        }
    }    
    return ans;
    }
};
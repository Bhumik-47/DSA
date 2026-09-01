class Solution {
public:
    int fun(vector<int>&nums, int g){
        if(g<0)return 0;
        int a=0,cs=0,j=0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            while(cs>g){
            
                cs-=nums[j++];
                
            }
            a+=i-j+1;
        }
        return a;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return fun(nums,goal)-fun(nums,goal-1);
    }
};
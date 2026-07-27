class Solution {
public:
int fun1(vector<int>& nums, int i){
   int prev2=0,prev1=0,curr=0;
   for(int j=i;j<nums.size();j++){
       curr=max(prev2+nums[j],prev1);
       prev2=prev1;
       prev1=curr;
   }
   return prev1;
}
int fun2(vector<int>nums){
    int prev2=0,prev1=0,curr=0;
   for(int j=0;j<nums.size()-1;j++){
       curr=max(prev2+nums[j],prev1);
       prev2=prev1;
       prev1=curr;
   }
   return prev1;
}
    int rob(vector<int>& nums) {
    if(nums.size()==1)return nums[0];        
    return max(fun1(nums,1),fun2(nums));
    }
};
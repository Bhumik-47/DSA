class Solution {
public:
    bool rec(vector<int>&nums , int i, int j, int p1, int p2, int ch){
        if(i<=j){
            if(ch){
                return rec(nums,i+1,j,p1+nums[i],p2,0)||rec(nums,i,j-1,p1+nums[j],p2,0);
            }
            else{
                return rec(nums,i+1,j,p1,p2+nums[i],1)&&rec(nums,i,j-1,p1,p2+nums[j],1);
            }
            
        }
    
      return p1>=p2;
    
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,ch=1;
        int p1=0,p2=0;
        return rec(nums,i,j,p1,p2,ch);
        
    }
};
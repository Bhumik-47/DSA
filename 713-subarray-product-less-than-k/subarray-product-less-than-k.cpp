class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        unsigned long long p=1;
        int ans=0;
        for(int e=0;e<n;e++){
           for(int s=e;s<n;s++){
             p=p*nums[s];
             if(p<k)ans++;
             else break;
           }
           p=1;
          
        }
        return ans;
    }
};
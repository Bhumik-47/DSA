class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int min_val=nums1[0];
        int min_od=2e9+1;
        bool ha_od=false;
        for(int i=0; i<n; i++){
            if(nums1[i]<min_val) min_val=nums1[i];
        
        if(nums1[i]%2!=0){
            ha_od=true;
            if(nums1[i]<min_od) min_od=nums1[i];
        }
        }
        if(!ha_od) return true;
        if(min_val%2!=0) return true;
        return false;
    }
};
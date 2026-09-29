class Solution {
public:
    void mergesort(vector<int>& nums, int l, int r){
        if(l>=r)return;
        int mid=l+(r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        int s1=l,s2=mid+1;
        vector<int>temp;
        while(s1<=mid && s2<=r){
            if(nums[s1]<=nums[s2]){
                temp.push_back(nums[s1++]);
            }
            else{
                temp.push_back(nums[s2++]);
            }
        }
        while(s1<=mid){
            temp.push_back(nums[s1++]);
        }
        while(s2<=r){
            temp.push_back(nums[s2++]);
        }
        int i=l;
        int j=0;
        while(i<=r){
            nums[i++]=temp[j++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
    mergesort(nums,0,nums.size()-1);
    return nums;
    }  
};
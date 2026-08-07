class NumArray {
public:
vector<int>pr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pr.resize(n);
        pr[0]=nums[0];
        for(int i=1;i<n;i++)pr[i]=pr[i-1]+nums[i];
        
    }
    
    int sumRange(int left, int right) {
        if(left==0)return pr[right];
        return pr[right]-pr[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
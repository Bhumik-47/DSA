class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int j=0;j<n;j++){
            vector<int>v;
            for(int i=0;i<n;i++){
            if(nums[i]==nums[j])v.push_back(i);
            }
            if(v.size()==3 && v[0]<v[1] && v[1]<v[2] && v[1]-v[0] == v[2]-v[1])s.insert(nums[j]);
        }
        return s.size();
    }
};
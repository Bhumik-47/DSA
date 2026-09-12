class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
           mp[nums[i]].push_back(i);
        }
        int a=0;
        for(auto const &it:mp){
            if(it.second.size()>=3){
            bool p =0;
            int d=it.second[1]-it.second[0];
            for(int i=1;i<it.second.size();i++){
                if(it.second[i]-it.second[i-1]!=d){
                    p=1;
                    break;
                }
            }
            if(!p)a++;
            }
        }
        return a;
    }
};
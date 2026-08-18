class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>v(51,0);
        
        for(int e=0;e<=nums.size()-k;e++){
           
            vector<bool>b(51,false);
            for(int st=e;st<e+k;st++){
                b[nums[st]]=true;
            }
            for(int j=0;j<51;j++){
                if(b[j])v[j]++;
            }
              
        }
        for(int i=50;i>=0;i--){
            if(v[i]==1)return i;
        }
        return -1;

    }
};
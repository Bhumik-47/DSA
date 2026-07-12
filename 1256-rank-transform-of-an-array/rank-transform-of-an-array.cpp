class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int p=1;
        if(arr.size()==0)return {};
        if(arr.size()==1)return {1};
        for(int i=1;i<arr.size();++i){
            if(temp[i]==temp[i-1]){
                mp[temp[i]]=p;
            }
            else{
                if(i==1){
                    mp[temp[0]]=p;
                    mp[temp[1]]=++p;
                    continue;
                }
                else{
                ++p;
                mp[temp[i]]=p;
                }
            }
        }
        for(int i=0;i<arr.size();++i){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};
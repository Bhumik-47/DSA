class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int s=piles.size();
        int pair=s/3;
        int np=0;
        int ans=0;
        for(int i=1;i<s;i+=2){
         if(np==pair)break;
         else{
            ans+=piles[i];
            np++;
         }
        }
        return ans;
    }
};
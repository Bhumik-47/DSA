class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>triangle;
        for(int i=0; i<=rowIndex; i++){
            vector<int>curr(i+1);
            curr[0]=1;
            curr[i]=1;
            if(i>=2){
                for(int j=1; j<i; j++){
                    curr[j]=triangle[i-1][j-1]+triangle[i-1][j];
                }
            }
            triangle.push_back(curr);
            
        }
        return triangle[rowIndex];
    }
};
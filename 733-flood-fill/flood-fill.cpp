class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int oc=image[sr][sc];
        if(oc==color)return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           image[x][y]=color;
           int dx[4]={-1,0,1,0};
           int dy[4]={0,1,0,-1};
           for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==oc){
                q.push({nx,ny});
                image[nx][ny]=color;
            }
           }
        }
        return image;
    }
};
class Solution {
    vector<vector<int>> dir= {{-1,0},{1,0},{0,1},{0,-1}};
    int bfs(vector<vector<int>>& grid,int r,int c){
        int ans=0; queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int i= q.front().first,j=q.front().second; q.pop();
            ans += grid[i][j]; grid[i][j]=0;
             for(auto k:dir){
                int ni= i+k[0],nj=j+k[1];
                if(ni>=0 && nj>=0 && nj< grid[0].size() && ni<grid.size() && grid[ni][nj]>0){
                    q.push({ni,nj});
                }
             }
        }
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] >0) ans= max(ans,bfs(grid,i,j));
            }
        }
        return ans;
    }
};
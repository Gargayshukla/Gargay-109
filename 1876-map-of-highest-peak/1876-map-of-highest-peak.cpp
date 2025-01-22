class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& m) {
        queue<pair<int,int>> q;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1){
                    m[i][j]=0;
                    q.push({i,j});
                }else{
                    m[i][j]=INT_MAX;
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            vector<int> dir={-1,0,1,0,-1};
            for(int i=0;i<4;i++){
                int rr=r+dir[i];
                int cc=c+dir[i+1];
                if(rr>=0 and rr<m.size() and cc>=0 and cc<m[0].size() and m[rr][cc]!=0){
                    if(m[rr][cc]>m[r][c]+1){
                        m[rr][cc]=m[r][c]+1;
                        q.push({rr,cc});
                    }
                    // m[rr][cc]=min(m[rr][cc],m[r][c]+1);
                    
                }
            }
        }
        return m;
    }
};
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();
        int res[n][m];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                res[i][j] = 0;
            }
        }

        int c[] = {-1,0,1};

        int mov = 0;

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            q.push({i,0});
            res[i][0] = 1;
        }

        while(!q.empty())
        {
            int size = q.size();
        

        for(int j=0; j<size; j++)
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int k=0; k<3; k++)
            {
                int e = x + c[k];
                int f = y+1;

                if(e >= 0 && e<n && f >= 0 && f<m && grid[e][f] > grid[x][y]  && !res[e][f])
                {
                    res[e][f] = 1;
                    q.push({e,f});
                }
            }
        }
      mov++;
    }
    ans = max(ans, mov-1);

    return ans;
        
    }
};
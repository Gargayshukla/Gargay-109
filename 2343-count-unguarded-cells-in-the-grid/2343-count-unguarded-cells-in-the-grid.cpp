class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m,vector<int>(n,0));
        int g = guards.size();
        int w = walls.size();
        
        for(int i= 0; i<g; i++)
        {
            int row = guards[i][0];
            int col = guards[i][1];
            grid[row][col] = 2;
        }
     
        for(int j=0; j<w; j++)
        {
            int row = walls[j][0];
            int col = walls[j][1];
            grid[row][col] = 3;
        }
       
        for(int i=0; i<g; i++) // O(g * (m+n))
        {
           int row = guards[i][0];
           int col = guards[i][1];
           // up
           for(int r = row-1; r >= 0; r--)
           {
                if(grid[r][col] == 2 or grid[r][col] == 3) break;
                grid[r][col] = 1;
           }
           //down
           for(int r = row+1; r < m; r++)
           {
                if(grid[r][col] == 2 or grid[r][col] == 3) break;
                grid[r][col] = 1;
           }
           //left
           for(int c = col-1; c >= 0; c--)
           {
                if(grid[row][c] == 2 or grid[row][c] == 3) break;
                grid[row][c] = 1;
           }
           //right 
           for(int c = col+1; c < n; c++)
           {
                if(grid[row][c] == 2 or grid[row][c] == 3) break;
                grid[row][c] = 1;
           }
        }
        int ans = 0;
       
        for(int i=0; i<m; i++) // O(m * n)
        { 
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) ans++;
            }
        }
        return ans;

 
    }
};
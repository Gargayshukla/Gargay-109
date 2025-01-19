class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n == 1 ) return 0; // Handle edge case for empty grid
        int m = heightMap[0].size();
        if (m == 0) return 0; // Handle edge case for empty grid

        // Min-heap (priority queue) to keep track of boundary cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Add boundary cells to the heap and mark them as visited
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            vis[i][0] = 1;
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0, j}});
            vis[0][j] = 1;
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            vis[n - 1][j] = 1;
        }

        // Directions for moving up, down, left, and right
        int up[] = {-1, 0, 1, 0};
        int down[] = {0, 1, 0, -1};

        int ans = 0;

        // Process cells in the heap
        while (!pq.empty()) {
            int height = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + up[i];
                int ncol = col + down[i];

                // Check bounds and if the cell is already visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1; // Mark as visited             
                    int newHeight=heightMap[nrow][ncol];
                    if(height>heightMap[nrow][ncol])
                    {
                        newHeight=height;
                        ans+=height-heightMap[nrow][ncol];
                    }
                    
                   
                    pq.push({newHeight, {nrow, ncol}});
                }
            }
        }

        return ans;
    }
};
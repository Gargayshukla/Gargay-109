class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;  
    dq.push_front({0, 0});
    dist[0][0] = 0;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newDist = dist[x][y] + grid[nx][ny];
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    if (grid[nx][ny] == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny}); 
                }
            }
        }
    }

    return dist[m - 1][n - 1]; 
    }
};
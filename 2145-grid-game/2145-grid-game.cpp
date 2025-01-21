class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);
        
        // Calculate prefix sums for both rows
        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];
        
        for (int i = 1; i < n; i++) {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }
        
        // Initialize the result to a very large value
        long long result = LLONG_MAX;
        
        // Evaluate each column as the transition point for the first robot
        for (int i = 0; i < n; i++) {
            long long pointsTop = (i + 1 < n) ? prefixTop[n - 1] - prefixTop[i] : 0; // Points remaining in the top row after the first robot
            long long pointsBottom = (i > 0) ? prefixBottom[i - 1] : 0;             // Points collected in the bottom row before the column
            
            // The second robot collects the maximum points from the remaining regions
            long long maxPointsSecondRobot = max(pointsTop, pointsBottom);
            result = min(result, maxPointsSecondRobot);
        }
        
        return result;
    }
};
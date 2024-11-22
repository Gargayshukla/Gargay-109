class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int ans = 0;

        while(matrix.size() > ans)
        {
            vector<vector<int>> res{};

            for(int i=1, j=0; i<matrix.size(); i++)
            {
                for(j = 0; j < matrix[0].size() && (matrix[0][0] ^ matrix[i][0]) == (matrix[0][j] ^ matrix[i][j]); j++);

                if(j != matrix[0].size())
                res.push_back(matrix[i]);
            }

            ans = max(ans, static_cast<int>(matrix.size() - res.size()));
            matrix = res;
        }

        return ans;
    }
};
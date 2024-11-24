class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n1 = matrix.size();
        int n2 = matrix[0].size();

        int s = 0;

        long long ans = 0;

        int mini = abs(matrix[0][0]);

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(matrix[i][j] <0)
                {
                    s++;
                }
                ans += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        

        if(s % 2==0)
        {
            return ans;
        }
        else
        {
            return ans - 2*mini;
        }
        
        
        
    }
};
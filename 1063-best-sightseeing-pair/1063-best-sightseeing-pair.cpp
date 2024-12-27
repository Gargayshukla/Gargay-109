class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();

        int ans = 0;
        int m = values[0];

        for(int i=1; i<n; i++)
        {
            ans = max(ans, m + values[i] - i);
            m = max(m, values[i]+i);
        }

      return ans;
    }
};
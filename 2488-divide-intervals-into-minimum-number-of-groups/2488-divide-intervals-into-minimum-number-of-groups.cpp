class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        int maxi = 0, len = 0;

        for(int i=0; i<n; i++)
        {
            len = max(len,intervals[i][1]);
        }

        vector<int> res(len+2,0);

        for(int i=0; i<n; i++)
        {
            res[intervals[i][0]]++;
            res[intervals[i][1]+1]--;
        
        }
        for(int i=1; i<res.size(); i++)
        {
            res[i] += res[i-1];
        }

        for(int i=0; i<res.size(); i++)
        {
            maxi = max(maxi, res[i]);
        }

        return maxi;
    }
};
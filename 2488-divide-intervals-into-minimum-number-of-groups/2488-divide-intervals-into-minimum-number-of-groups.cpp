class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        int res[1000005] = {0};
        int len = INT_MIN;

        for(int i=0; i<n; i++)
        {
            res[intervals[i][0]]++;
            res[intervals[i][1]+1]--;
            len = max(len,intervals[i][1]);
        }

    int maxi = 0, ans = 0;
    
        for(int i=1; i<=len; i++)
        {
            ans += res[i];
            maxi = max(maxi,ans);
        }

        return maxi;
    }
};
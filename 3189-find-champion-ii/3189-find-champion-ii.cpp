class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> ans(n,0);

        for(auto s : edges)
        {
            ans[s[1]]++;
        }

        int c = -1, ct = 0;

        for(int i=0; i<n; i++)
        {
            if(ans[i] == 0)
            {
                ct++;
                c = i;
            }
        }
        
        
        return ct > 1 ? -1 : c;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=0;
        vector<int> row(m, 0), col(n, 0);
        vector<int> oneElem;
        for(int i=0; i<m; i++){
            int lastj=-1;
            for(int j=0; j<n; j++) if(grid[i][j]) row[i]++, col[j]++, lastj=j;
            if(row[i]>1) res+=row[i];
            else if(row[i]==1) oneElem.push_back(lastj);
        }
        for(auto& j: oneElem) if(col[j]>1) res++;
        return res;
    }
};
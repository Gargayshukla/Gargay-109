class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m= mat.size(),n=mat[0].size();

        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            mp[mat[i][j]]={i,j};
        }

        vector<int> row(m,n),col(n,m);

        for(int i=0;i<m*n;i++)
        {
            row[mp[arr[i]].first]-- ;
            col[mp[arr[i]].second]--;
            if(!row[mp[arr[i]].first] || !col[mp[arr[i]].second])
            return i;
        }

        return -1;
        
    }
};
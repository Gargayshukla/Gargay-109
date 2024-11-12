class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n1 = items.size();
        int n2 = queries.size();

        sort(items.begin(), items.end());

        vector<int> ans;

        for(int i=1; i<n1; i++)
        {
            items[i][1] = max(items[i][1], items[i-1][1]);
        }

        for(int i=0; i<n2; i++)
        {
            int s = 0;
            int e = n1 - 1;
            int res = 0;

            while(s<=e)
            {
                int mid = s+(e-s)/2;

                if(items[mid][0] <= queries[i])
                {
                    res = items[mid][1];
                    s = mid+1;
                }
                else
                {
                    e = mid-1;
                }

            }

            ans.push_back(res);
        }

      return ans;
    }
};
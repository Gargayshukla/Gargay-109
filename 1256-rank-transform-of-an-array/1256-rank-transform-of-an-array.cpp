class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();

        unordered_map<int,int> m;

        vector<int> ans;
        ans = arr;
        int rank = 0;

        sort(arr.begin(),arr.end());

        for(int i = 0; i<n; i++)
        {
            if(m.find(arr[i]) == m.end())
            {
                rank++;
                m[arr[i]] = rank;
            }
        }

        for(int i = 0; i<ans.size(); i++)
        {
            ans[i] = m[ans[i]];
        }

        return ans;
    }
};
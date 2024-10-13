class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i<=n-k; i++)
        {
            map<int,int> res;

            for(int j = i; j<i+k; j++)
            {
                res[nums[j]]++;
            }

            vector<pair<int,int>> occ;

            for(auto &[i, count] : res)
            {
                occ.push_back({i, count});
            }

            sort(occ.begin(), occ.end(), [] (const pair<int,int> & a, const pair<int,int> &b)
            {
                if(a.second != b.second)
                {
                    return a.second > b.second;
                }
                return a.first > b.first;
            });

          int total = 0;

          for(int j = 0; j<min(x,(int) occ.size()); j++)
          {
            total += occ[j].first * occ[j].second;
          }

          ans.push_back(total);
        }

        return ans;
    }
};
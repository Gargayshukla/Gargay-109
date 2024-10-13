class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        vector<pair<int,int>> ans;
        
        int start = -1, end = -1;
        int min = INT_MAX;

        for(int i=0; i<n; i++)
        {
            mp[i]++;
        }

         for(int i = 0; i<n; i++)
         {
            for(int j = 0; j<nums[i].size(); j++)
            {
                ans.push_back({nums[i][j],i});
            }
         }

         int i = 0, j = 0;

         sort(ans.begin(), ans.end());
         int req = n;

         while(j<ans.size())
         {
            int val = ans[j].second;

            if(mp[val] > 0)
            {
                req--;
            }

            mp[val]--;

            if(req == 0)
            {
                while(req==0){
                    if(min > ans[j].first - ans[i].first)
                    {
                        start = ans[i].first;
                        end = ans[j].first;
                        min = ans[j].first  - ans[i].first;
                    }

                    mp[ans[i].second]++;

                    if(mp[ans[i].second] >0 )
                    {
                        req++;
                    }
                    i++;
                }
            }
            j++;
         }

      return {start,end};
    }
};
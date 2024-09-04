class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<vector<int>> ans;

        //Sort the Array
        sort(intervals.begin(),intervals.end());

        for(int i=0; i<n; i++)
        {
            //single element
            if(ans.empty())
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> &curr = ans.back();
                int j = curr[1];

                if(intervals[i][0] <= j)
                {
                    curr[1] = max(j,intervals[i][1]);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }


        }

      return ans;
    }
};
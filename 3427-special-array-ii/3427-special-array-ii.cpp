class Solution {
    bool same(int &a, int &b)
    {
        return (a % 2 == b % 2);
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            if(i == 0 || same(nums[i], nums[i-1]))
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(ans.back());
            }
        }

            vector<bool> res;

            for(auto i : queries)
            {
                int id = i[1];
                int rq = i[0];

                res.push_back(ans[id] <= rq);
            }
        
        

        return res;
    }
};
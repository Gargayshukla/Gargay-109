class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();

        int max = *max_element(begin(candies),end(candies));

        vector<bool> ans(n,false);

        for(int i = 0; i<n; i++)
        {
            if(candies[i] + extraCandies >= max)
            {
                ans[i] = true;
            }
        }

        return ans;
    }
};
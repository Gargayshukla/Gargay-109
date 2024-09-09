class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();

        //storing maximum element from array i.e 5
        //if  2 + 3 >= 5 return true
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
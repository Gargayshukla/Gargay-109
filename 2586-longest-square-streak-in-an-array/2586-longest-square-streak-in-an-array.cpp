class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int n = nums.size();

        map<int, int> s;
        int ans = 1;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int j = nums[i];

            int res = int(sqrt(j));

            if(res * res == j)
              
              s[j] += s[res];
              s[j] += 1;
              ans = max(ans, s[j]);
        }

        return ans == 1 ? -1 : ans;
    }
};
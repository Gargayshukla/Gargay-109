class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> s(n, 1), e(n, 1);

        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[i] > nums[j])
                {
                    s[i] = max(s[i], 1 + s[j]);
                }
            }
        }


        for(int i = n-2; i>=0; i--)
        {
            for(int j = n-1; j>i; j--)
            {
                if(nums[i] > nums[j])
                {
                    e[i] = max(e[i], 1 + e[j]);
                }
            }

        }

            int ans = 0;

            for(int i=1; i<n; i++)
            {
                if(s[i] != 1 & e[i] != 1)
                {
                    ans = max(ans, s[i] + e[i]);
                }
            }

      return n - ans + 1;
    }
};
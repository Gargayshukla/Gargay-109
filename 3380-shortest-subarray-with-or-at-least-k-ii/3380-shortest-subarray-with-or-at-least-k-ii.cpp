class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int n1 = INT_MAX;
        int m = 0;

        vector<int> ans(32, 0);

        for(int i = 0; i<n; i++)
        {
            if(nums[i] >= k)
            {
                return 1;
            }

            long long s = 0, e = 1;

            for(int j = 0; j < 32; j++)
            {
                if(nums[i] & (1<<j))
                {
                    ans[j]++;
                }
                if(ans[j] > 0)
                {
                    s += e;
                }
                e = e<<1;
            }

            while(s>=k)
            {
                n1 = min(n1, i-m+1);

                for(int j = 0; j<32; j++)
                {
                    if(nums[m] & (1<<j))
                    {
                        ans[j]--;
                    }
                }
                m++;

                s = 0; e = 1;

                for(int j = 0; j<32; j++)
                {
                    if(ans[j] > 0) 
                    s += e;
                    e = e<<1;
                }
            }
        }

        return n1 == INT_MAX ? -1 : n1;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
        {
            if(nums[0] < target)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int sum = 0;

        while(i<=j && j<n)
        {
            sum = sum + nums[j];

            if(sum >= target)
            {
                while(sum>=target)
                {
                    ans = min(ans,(j-i)+1);

                    sum = sum - nums[i];
                    i++;
                }
            }
            j++;
        }

        if(ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};
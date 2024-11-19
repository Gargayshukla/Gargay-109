class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        long long ans = 0, tot = 0;
        int i = 0, j = 0;

        unordered_set<int> s;

        while(j<n)
        {
            while(s.count(nums[j]))
            {
                tot -= nums[i];
                s.erase(nums[i]);
                i++;
            }

            tot += nums[j];
            s.insert(nums[j]);

            if(s.size() ==k)
            {
                ans = max(ans,tot);
                tot -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            j++;
        }

        return ans;
    }
};
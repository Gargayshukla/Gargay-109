class Solution {
public:
    long long ans(vector<int>& nums, int val)
    {
        long res = 0;

        for(int i=0, j=nums.size()-1; i<j; i++)
        {
            while(i<j && nums[i] + nums[j] > val)
            {
                j--;
            }

            res += j-i;
        }
        return res;
    }  
            
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(begin(nums), end(nums));

        return ans(nums, upper) - ans(nums, lower - 1);
    }
};
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int ans = nums[0];
        int curr = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
        if(nums[i] > nums[i-1])
        {
            curr = curr + nums[i];
        }
        else
        {
            ans = max(ans, curr);
            curr = nums[i];
        }
        }
        ans = max(ans,curr);

        return ans;
    }
};
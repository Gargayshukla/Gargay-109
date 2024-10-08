class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                count = 0;
            }
            else
            {
               count++;
               ans = max(ans,count);
            }
        }

       return ans;
    }
};
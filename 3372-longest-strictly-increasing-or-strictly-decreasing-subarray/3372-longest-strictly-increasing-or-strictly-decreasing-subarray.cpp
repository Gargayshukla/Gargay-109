class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int s = 1;
        int e = 1;

        int ans = 0;
        int i = 0;

        if(n == 1)
        {
            return 1;
        }

        for(i=1 ;i<n; i++){
            if (nums[i]>nums[i-1]) s++, e=1;
            else if (nums[i]<nums[i-1]) s=1, e++;
            else s=e=1;
            ans=max({ans, e, s});
        } 

      return ans;
    }
};
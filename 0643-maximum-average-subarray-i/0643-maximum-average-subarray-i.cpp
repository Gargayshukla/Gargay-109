class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();

        double ans = 0;
        double window = 0;
         
         for(int i=0; i<k; i++)
         {
            window = window + nums[i];
         }
         ans = window/k;

         for(int right = k; right<n; right++)
         {
            window = window + nums[right] - nums[right - k];
            ans = max(ans,window/k);
         }

         return ans;
    }
};
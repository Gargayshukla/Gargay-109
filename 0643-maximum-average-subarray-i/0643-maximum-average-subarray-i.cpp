class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();

        double ans = 0; // storing ans
        double window = 0; // for first window
         
         for(int i=0; i<k; i++)
         {
            window = window + nums[i];  //ans for first window
         }
         ans = window/k;  // avg of first window

         for(int right = k; right<n; right++)
         {
            window = window + nums[right] - nums[right - k];
            ans = max(ans,window/k);
         }

         return ans;
    }
};
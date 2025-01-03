class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

      int ans = 0;

      long int s = 0, e = 0;

      int n = nums.size()  ;

      for(int i=0; i<n; i++)
      {
        e = e+nums[i];
      }

      for(int i=0; i<n-1; i++)
      {
        s = s + nums[i];
        e = e - nums[i];

        if(s >= e)
        {
            ans++;
        }
      }

      return ans;
    }
};
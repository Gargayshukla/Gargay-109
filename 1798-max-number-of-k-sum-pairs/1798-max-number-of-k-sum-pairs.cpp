class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

    // Approach - 
    // sort the Array
    //intialise i = 0, j = n-1;
    // nums[i] + nums[j] return ans++ shift the pointers to next
    // else if the sum is less than k than increment i or if the sum ids greater than decre j

        
      int n = nums.size();
      int i = 0;
      int j = n-1;

      int ans = 0;

      sort(nums.begin(),nums.end());

      while(i<j)
      {
        if(nums[i] + nums[j] == k)
        {
            i++;
            j--;
            ans++;
        }
        else if(nums[i] + nums[j] < k)
        {
            i++;
        }
        else if(nums[i] + nums[j] > k)
        {
            j--;
        }
      }

      return ans;
    }
};
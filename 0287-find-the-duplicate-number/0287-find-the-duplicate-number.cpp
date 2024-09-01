class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ans = 0;

        if(nums.size() < 0)
        {
            return -1;
        }

        if(nums.size() <=2)
        {
            return nums[0];
        }

        sort(nums.begin(),nums.end());
     
        for(int i=0; i<nums.size(); i++)
        {
                if( nums[i] == nums[i+1])
                {
                    ans =  nums[i];
                }
        }
       return ans;
    }
};
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        int total = 0;

        for(int i = 0; i<n; i++)
        {
            total = (total + nums[i]) % p;
        }

        int rem = total % p;

        if(rem == 0)
        {
            return 0;
        }

        unordered_map<int, int> mod;
        mod[0] = -1;
        int minl = n;
        int curr = 0;

        for(int i=0; i<n; i++)
        {
           
            curr = (curr + nums[i]) % p;

            int tar = (curr - rem + p) %p;

            if(mod.find(tar) != mod.end())
            {
             minl = min(minl, i - mod[tar]);
            }

            mod[curr] = i;
        }

        return minl == n ? -1 : minl;
        
    }
};
class Solution {
public:

    int valid(int val, int &s)
    {
       int ans = val-1;

       while(ans)
       {
        if((isprime(ans)) && (val - ans > s))
        {
            return ans;
        }
        ans--;
       }
       return -1;
    }

    bool isprime(int val)
    {
        if(val == 1)
        {
            return false;
        }

        int mid = val/2;

        for(int i=2; i<=mid; i++)
        {
            if(val % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        
        int n = nums.size();
        int s = 0;

        for(int i=0; i<n; i++)
        {
            int prime = valid(nums[i], s);
            if(prime != -1)
            {
                nums[i] = nums[i] - prime;
            }

            s = nums[i];
        }

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] >= nums[i+1])
            {
                return false;
            }
        }

        return true;
    }
};
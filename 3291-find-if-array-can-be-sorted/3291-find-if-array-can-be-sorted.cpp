class Solution {
public:
    int bit(int n)
    {
        int cnt = 0;

        while(n>0)
        {
            cnt++;
            n = n & (n-1);
        }

        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        
        bool sort = false;

        while(!sort)
        {
        sort = true;
           for(int i=0; i<nums.size()-1; i++)
           {
             if(bit(nums[i]) == bit(nums[i+1]) && nums[i] > nums[i+1])
             {
                std::swap(nums[i], nums[i+1]);
                sort = false;
             }
           }
        }

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
                return false;
            
        }

        return true;
    }
};
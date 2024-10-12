class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n);

        for(int i=0; i<n; i++)
        {
            int min = nums[i];
            int mini = std::numeric_limits<int>::max();
            bool found = false;
            for(int j=0; j < 31; j++)
            {
                if((min >> j) & 1)
                {
                    int c = min & ~(1 << j);
                    
                        if(c<0)
                            continue;
            
                if((c| (c+1)) == min)
                {
                    if(c < mini){
                    mini = c;
                    found = true;
                    }
                }
            }
            }
           ans[i] = found ? mini : -1;
        }

        return ans;
    }
};
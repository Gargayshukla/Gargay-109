class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        stack<int> s;

        s.push(0);

        for(int i=0; i<n; i++)
        {
            if(nums[i] < nums[s.top()])
            {
                s.push(i);
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && nums[s.top()] <= nums[i])
            {
                ans = max(ans,i-s.top());
                s.pop();
            }
        }

        return ans;
    }
};
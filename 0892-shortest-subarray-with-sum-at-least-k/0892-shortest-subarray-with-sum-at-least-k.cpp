class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<long> prefix(n+1, 0);

        for(int i=0; i<n; i++)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int mini = INT_MAX;

        for(int i=0; i<=n; i++){
        while(!dq.empty() && prefix[i] - prefix[dq.front()] >=k)
        {
            mini = min(mini, i-dq.front());
            dq.pop_front();
        }

        while(!dq.empty() && prefix[i]<=prefix[dq.back()])
        {
            dq.pop_back();
        }
    
         dq.push_back(i);

        }
         return mini == INT_MAX ? -1 : mini;

    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        double avg = 0;
        double window = 0;

        for(int i=0; i<k; i++)
        {
            window = window + nums[i];
        }
        avg = window/k;

        for(int right = k; right<n; right++)
        {
            window = window + nums[right] - nums[right-k];
            avg = max(avg,window/k);
        }

        return avg;
    }
};
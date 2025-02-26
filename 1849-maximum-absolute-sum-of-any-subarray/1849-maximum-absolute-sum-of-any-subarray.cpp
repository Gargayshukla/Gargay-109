class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = 0;
        for (int val : nums){
            cur_sum += val;
            if (cur_sum < 0){
                cur_sum = 0;
            }
            max_sum = max( cur_sum, max_sum);
        }
        
        int curr_sum = 0;
        int min_sum = 0;
        for (int val : nums){
            curr_sum += val;
            
            if (curr_sum > 0){
                curr_sum = 0;
            }
            min_sum = min(curr_sum, min_sum);
        }
        return max(max_sum, abs(min_sum));
    }
};
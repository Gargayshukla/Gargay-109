class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();

        for(int i=0; i<k; i++)
        {
            int m = *min_element(nums.begin(), nums.end());

            for(int j=0; j<n; j++)
            {
                if(nums.at(j) == m)
                {
                    nums.at(j) *= multiplier;
                    break;
                }
            }
        }

        return nums;
    }
};
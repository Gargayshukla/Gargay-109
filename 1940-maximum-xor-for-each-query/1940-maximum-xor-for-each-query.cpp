class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();

        vector<int> res(n+1);

        res[0] = pow(2, maximumBit) - 1;

        for(int i = 0; i<n; i++)
        {
            res[i+1] = res[i] ^ nums[i];
        }

        reverse(res.begin(), res.end());
        res.pop_back();

        return res;
    }
};
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l = 1, h = *max_element(nums.begin(), nums.end());

        while(l < h)
        {
            int mid = l + (h-l)/2;

            int count = 0;

            for(int i : nums) if((count += (i-1) / mid) > maxOperations)
            break;

            count <= maxOperations ? h = mid : l = mid+1;
        }

        return h;
    }
};
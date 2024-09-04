class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int ans = 0;

        //Approach -

        //Agar nums[i] equal nahi hai val khe tho i kho ans mhe store kar deghe agar, 
        //agar equal aha raha store nahi karenge
        //count ans & return it
        
        for(int i=0; i<n; i++){
        if(nums[i] != val)
        {
           nums[ans] = nums[i];
           ans++;
        }

        }

        return ans;
    }
};
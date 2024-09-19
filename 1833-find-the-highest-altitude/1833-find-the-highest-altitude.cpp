class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        int ans = 0;
        int curr = 0;

        for(int i=0; i<n; i++)
        {
            curr = curr + gain[i];
            ans = max(curr, ans);
        }

        return ans;
    }
};